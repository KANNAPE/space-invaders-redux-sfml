#ifndef __UI_OBJECT_H__
#define __UI_OBJECT_H__

#include "GameObject/GameObjectBase.h"

#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"

class UIObject : public GameObjectBase
{
public:
	UIObject();
	UIObject(const sf::Vector2f& position);

	void update(float delta) override;

	virtual void onSelect() {}
	virtual void onUnselect() {}
	virtual void onValidate() {}
	
protected:
	bool m_isHovered;
};

#endif //__UI_OBJECT_H__