#pragma once
#include "../../common.hpp"

struct vmatrix_t {
	union
	{
		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4];
	};
};
inline class c_camera {
private:
	Vector3 position;
	vmatrix_t vmatrix{};
	uint64_t cameraObj;
public:
	bool setPosition(Vector3 _position) {
		position = _position;
		return (bool)(position == _position);
	}
	void setVmatrix(vmatrix_t _vmatrix) {
		vmatrix = _vmatrix;
	}

	Vector3 getPosition() {
		return position;
	}
	vmatrix_t getVmatrix() {
		return vmatrix; // vMatrix = 0x304 | 0x100 | 0x7C
	}

	uint64_t getObject() {
		if (cameraObj == 0 || !memory.valid(cameraObj)) {
			uint64_t camera = memory.read<uint64_t>(memory.module + oMain::oMainCamera);
			uint64_t staticFields = memory.read<uint64_t>(camera + 0xB8);
			uint64_t cameraPtr = memory.read<uint64_t>(staticFields + 0xB8);
			cameraObj = memory.read<uint64_t>(cameraPtr + 0x10);
		}
		return cameraObj;
	}
} camera;

inline bool w2s(const Vector3& wPos, Vector2& sPos) {
	Vector3 transform{ camera.getVmatrix()._14, camera.getVmatrix()._24, camera.getVmatrix()._34 };
	Vector3 right{ camera.getVmatrix()._11, camera.getVmatrix()._21, camera.getVmatrix()._31 };
	Vector3 up{ camera.getVmatrix()._12, camera.getVmatrix()._22, camera.getVmatrix()._32 };

	float w = transform.dot(wPos) + camera.getVmatrix()._44;
	if (w < 0.098f)
		return false;

	Vector2 pos{ right.dot(wPos) + camera.getVmatrix()._41, up.dot(wPos) + camera.getVmatrix()._42 };
	sPos = Vector2(globals.screen_center_x * (1 + pos.x / w), globals.screen_center_y * (1 - pos.y / w));
	//sPos = Vector2((1920 / 2.0f) * (1.0f + pos.x / w), (1080 / 2.0f) * (1.0f - pos.x / w));

	return true;
}