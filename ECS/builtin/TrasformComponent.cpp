#include "TrasformComponent.h"

vec2f TransformComponent::position()
{
	return this->lPos;
}

vec2f TransformComponent::localPosition()
{
	return this->gPos;
}

void TransformComponent::updateGlobalPosition()
{
	if (parent) {
		this->gPos = parent->position() + this->lPos;
	}
}

void TransformComponent::updateLocalPosition()
{
	if (parent) {
		this->lPos = this->gPos - parent->position();
	}
	else {
		this->lPos = this->gPos;
	}
}


void TransformComponent::setPosition(float x, float y)
{
	this->gPos.set(x, y);
	this->updateLocalPosition();
}

void TransformComponent::setLocalPosition(float x, float y)
{
	this->lPos.set(x, y);
	updateGlobalPosition();
}

void TransformComponent::setParent(TransformComponent * parent, bool stayGlobalPosition = false)
{
	this->parent = parent;
	if (parent) {
		if (stayGlobalPosition) {
			this->updateLocalPosition();
		}
		else {
			updateGlobalPosition();
		}
	}
	else {
		this->lPos.set(0, 0);
	}
}
