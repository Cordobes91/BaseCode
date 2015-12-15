#include "MenuState.h"
#include "PlayState.h"
#include "GameObjectFactory.h"
#include "StateParser.h"


const std::string MenuState::s_menuID = "MENU";


bool MenuState::onEnter(){


	StateParser stateParser;
	stateParser.parseState("tiny.xml", s_menuID, &m_gameObjects, &m_textureIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	setCallbacks(m_callbacks);


return true;



}


void MenuState::update(){


	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}



/*bool MenuState::onExit() {


	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}



	m_gameObjects.clear();

	for (int i = 0; i < m_textureIDList.size(); i++) {



		TheTextureManager->clearFromTextureMap(m_textureIDList[i]);



	}



	*/




//


void MenuState::render(){


	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}



}


bool MenuState::onExit(){


	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}



	m_gameObjects.clear();

	for (int i = 0; i < m_textureIDList.size(); i++){



		TheTextureManager->clearFromTextureMap(m_textureIDList[i]);



	}




	m_textureIDList.clear();

	return true;
}


void MenuState::s_menuToPlay(){



	//llamamos

	Game::Instance()->getGameStateMachine()->changeState(new PlayState());
}



void MenuState::s_exitFromMenu(){


	Game::Instance()->getGameStateMachine()->popState();
	Game::Instance()->getGameStateMachine()->deleteAllStates();
	Game::Instance()->exit();


}


//

void MenuState::setCallbacks(const std::vector<Callback>&callbacks){


	for (int i = 0; i < m_gameObjects.size(); i++){



		if (dynamic_cast<MenuButton*>(m_gameObjects[i])){



			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);


		}



	}



}