#include "MenuButton.h"



MenuButton::MenuButton(){



}


void MenuButton::load(const Params* pParams){


	GameObject::load(pParams);
	m_callbackID = pParams->getCallbackID();
	m_bReleased = false;
	m_currentFrame = MOUSE_OUT;
}


void MenuButton::draw(){


	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), m_flip);


}


void MenuButton::update(){



	Vector2D pMousePos = InputHandler::Instance()->getMousePosition();
	if (pMousePos.getX() < (m_position.getX() + m_width)&& pMousePos.getX() > m_position.getX()&& pMousePos.getY() < (m_position.getY() + m_height)&& pMousePos.getY() > m_position.getY()){


		if (InputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased){

			m_currentFrame = CLICKED;
			m_callback();
			m_bReleased = false;





		}else if (!InputHandler::Instance()->getMouseButtonState(LEFT)){


			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}




	}else{


		m_currentFrame = MOUSE_OUT;



	}
}


void MenuButton::clean(){


	GameObject::clean();


}