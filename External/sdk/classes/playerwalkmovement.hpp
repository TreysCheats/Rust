#pragma once
#include "../../common.hpp"

class c_PlayerWalkMovement {
public:
	uint64_t getAddress() {
		return reinterpret_cast<uint64_t>(this);
	}

	void setCapsuleCenter(float center) {
		memory.write<float>(getAddress() + oPlayerWalkMovement::oCapsuleCenter, center);
	}
	void setSprinting(float sprinting) {
		memory.write<float>(getAddress() + oBaseMovement::oSprinting, sprinting);
	}
	void setGrounded(float grounded) {
		memory.write<float>(getAddress() + oBaseMovement::oGrounded, grounded);
	}
	void setMaxAngleWalking(float angle) {
		memory.write<float>(getAddress() + oPlayerWalkMovement::oMaxAngleWalking, angle);
	}
	void setMaxAngleClimbing(float angle) {
		memory.write<float>(getAddress() + oPlayerWalkMovement::oMaxAngleClimbing, angle);
	}
	void setGroundAngle(float angle) {
		memory.write<float>(getAddress() + oPlayerWalkMovement::oGroundAngle, angle);
	}
	void setGroundAngleNew(float angle) {
		memory.write<float>(getAddress() + oPlayerWalkMovement::oGroundAngleNew, angle);
	}
	void setJumpTime(float time) {
		memory.write<float>(getAddress() + oPlayerWalkMovement::oJumpTime, time);
	}
	void setGroundTime(float time) {
		memory.write<float>(getAddress() + oPlayerWalkMovement::oGroundTime, time);
	}
	void setLandTime(float time) {
		memory.write<float>(getAddress() + oPlayerWalkMovement::oLandTime, time);
	}
};