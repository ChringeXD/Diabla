#pragma once

#include "Diabla/Input.h"

namespace Diabla {

	class WindowsInput : public Input
	{
	protected:
		virtual bool GetKeyDownImpl(int keycode) override;

		virtual bool GetMouseButtonDownImpl(int keycode) override;

		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}