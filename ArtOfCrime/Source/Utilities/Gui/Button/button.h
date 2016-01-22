#pragma once
#include "interactable.h"

namespace gui 
{
	class Button : public Interactable
	{
	public:
		Button();
		virtual ~Button();

		// Update this object.
		virtual void Update(sf::Vector2f windowsize);

		bool IsClicked() { return m_clicked; };
		void SetIsClicked(bool clicked) { m_clicked = clicked; };

		bool IsHoovered() { return m_hoovered; };

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		// Specifies what the object should do when hoovered. 
		virtual void OnHoover();

		// Specifies what the object should do when clicked.
		virtual void OnClick();

		virtual void UnHoover();

		virtual void UnClick();

		bool m_clicked, m_hoovered;

	};
}