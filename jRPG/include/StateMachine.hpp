//
//  StateMachine.hpp
//  jRPG
//
//  Here - finite state-machine class for every other classes
//  every state classes will be impemented for every known
//  gameObjects states.
//
//
//  Created by Антон on 14.02.18.
//  Copyright © 2018 Tohue. All rights reserved.
//

#ifndef StateMachine_hpp
#define StateMachine_hpp

#include <SFML/Graphics.hpp>


class State {
    
};

//*******************GAME STATES********************

class gameState : public State {
    
    virtual void update () {};
    
};

class gameStage : public gameState {
    
    virtual void update () {};
};

class gameBattle : public gameState {
    
    virtual void update () {};
};

class gameMenu : public gameState {
    
    virtual void update () {};
};


//*******************GG STATES********************

class ggState : public State {
    //virtual ~ggState() {};
    virtual void update () {};
    
};

class ggRunning : public ggState {
    
    virtual void update () {};
};

class ggStanding : public ggState {
    
    virtual void update () {};
};




//***************STATE MACHINES*******************


class StateMachine {
public:
    void change();
    
};


class gameStateMachine : public StateMachine {
public:
    static gameStage stage;
    static gameBattle battle;
    static gameMenu menu;

};


class ggStateMachine : public StateMachine {
public:
    
    static ggRunning running;
    static ggStanding standing;
    
    
};


#endif /* StateMachine_hpp */
