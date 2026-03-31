#ifndef __UI_OBJECT_H__
#define __UI_OBJECT_H__

#include "GameObject/GameObjectBase.h"

// Graphics
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Rect.hpp"
// System
#include "SFML/System/Vector2.hpp"

class UIObject : public GameObjectBase
{
public:
	virtual sf::FloatRect getBounds() const;

	virtual void onSelect() {}
	virtual void onUnselect() {}
	virtual void onValidate() {}
	
protected:
	void draw(sf::RenderTarget& /*target*/, sf::RenderStates /*states*/) const override {}
};

#endif //__UI_OBJECT_H__