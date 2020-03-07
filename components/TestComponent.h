#pragma once
#include "imports.h"

class TestComponent : public Component {
public:

	void start() override;

	void update();

private:
	vec2i _initialPos;
};