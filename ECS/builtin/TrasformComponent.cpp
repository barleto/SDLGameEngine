#include "TrasformComponent.h"

vec2i TransformComponent::position()
{
	return _lPos;
}

vec2i TransformComponent::localPosition()
{
	return this->_gPos;
}

void TransformComponent::updateGlobalPosition()
{
	if (_parent) {
		this->_gPos = _parent->position() + this->_lPos;
	}
}

void TransformComponent::updateLocalPosition()
{
	if (_parent) {
		this->_lPos = this->_gPos - _parent->position();
	}
	else {
		this->_lPos = this->_gPos;
	}
}


void TransformComponent::setPosition(float x, float y)
{
	this->_gPos.set(x, y);
	this->updateLocalPosition();
}

void TransformComponent::setLocalPosition(float x, float y)
{
	this->_lPos.set(x, y);
	updateGlobalPosition();
}

void TransformComponent::setParent(TransformComponent * parent, bool stayGlobalPosition = false)
{
	this->_parent = parent;
	if (parent) {
		if (stayGlobalPosition) {
			this->updateLocalPosition();
		}
		else {
			updateGlobalPosition();
		}
	}
	else {
		this->_lPos.set(0, 0);
	}
}

Entity * TransformComponent::parent()
{
	if(!_parent) return nullptr;
	return _parent->entity;
}
