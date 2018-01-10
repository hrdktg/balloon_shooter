#include "JoystickHandler.h"
#include "game.h"
/*
void Joystickhandler::init()
{
    if(SDL_WasInit(SDL_INIT_JOYSTICK)==0)
    {
        SDL_InitSubSystem(SDL_InitSubSystem(SDL_INIT_JOYSTICK));
    }

    if(SDL_NumJoysticks()>0)
    {
        SDL_Joystick* joy;
        for(int i=0;i<SDL_NumJoysticks();i++)
        {
            joy=SDL_JoystickOpen(i);
            cout<<"Joystick Added\n";
            m_joy.push_back(joy);

            std::vector<int> tmp;
            for(int j=0;j<12;j++) {
                tmp.push_back(0);
            }
            m_joyVal.push_back(tmp);

        }
        SDL_JoystickEventState(SDL_ENABLE);
        m_isJoyConnected=true;
    }
    else
        m_isJoyConnected=false;
}

void Joystickhandler::clean()
{
    if(m_isJoyConnected)
    {
        for(unsigned int i=0;i<SDL_NumJoysticks();i++)
        {
            SDL_JoystickClose(m_joy[i]);

        }
    }
}

void Joystickhandler::update()
{
    SDL_Event evt;
    while(SDL_PollEvent(&evt))
    {
        if(evt.type==SDL_QUIT)
        {
            Game::getInstance()->quit();
        }

        if(evt.type==SDL_JOYAXISMOTION)
        {
            int jId=evt.jaxis.which;
            int jAxis=evt.jaxis.axis;
            std::cout<<"AxisMotion:"<<jAxis<<" for controller:"<<jId<<"\n";
            m_joyVal[jId][jAxis]=(int)evt.jaxis.value;
        }
        else
        {
            if(evt.type==SDL_JOYBUTTONDOWN)
            {
                int jId=evt.jaxis.which;
                int jBtn=evt.jbutton.button;
                std::cout<<"BtnDOWN:"<<jBtn<<" for controller:"<<jId<<"\n";
                m_joyVal[jId][jBtn]=1;
            }
            else
            if(evt.type==SDL_JOYBUTTONUP)
            {
                int jId=evt.jaxis.which;
                int jBtn=evt.jbutton.button;
                std::cout<<"BtnUP:"<<jBtn<<" for controller:"<<jId<<"\n";
                m_joyVal[jId][jBtn]=0;
            }
            else
            if(evt.type==SDL_JOYHATMOTION)
            {
                int jId=evt.jhat.which;
                int joyHat=
                std::cout<<"jhat:"<<joyHat<<" for controller:"<<jId<<"\n";
            }
        }
    }
}

bool Joystickhandler::isConnected()
{
    return m_isJoyConnected;
}
*/

void JoystickHandler::addController(int jID) {
    cout<<"Adding:"<<jID<<"\n";
    if(SDL_IsGameController(jID))
    {
        SDL_GameController *pad=SDL_GameControllerOpen(jID);

        if(pad)
        {
            SDL_Joystick* joy=SDL_GameControllerGetJoystick(pad);
            
            m_joy[jID]=pad;
        }
    }
    m_isJoyConnected=true;
}

void JoystickHandler::removeController(int jID)
{
    cout<<"Removing:"<<jID<<"\n";
    SDL_GameController *pad=m_joy[jID];
    SDL_GameControllerClose(pad);

    if(!m_joy.size()) m_isJoyConnected=false;
}

void JoystickHandler::update()
{
    SDL_Event evt;

    while(SDL_PollEvent(&evt))
    {   
        if(evt.type==SDL_QUIT)
        {
            Game::getInstance()->quit();
        }
        switch(evt.type)
        {
            case SDL_CONTROLLERDEVICEADDED:
                addController(evt.cdevice.which);
                break;
            case SDL_CONTROLLERDEVICEREMOVED:
                removeController(evt.cdevice.which);
                break;
            case SDL_CONTROLLERBUTTONDOWN:
            case SDL_CONTROLLERBUTTONUP:
                cout<<evt.cbutton.button<<" Dumb\n";
                break;
            case SDL_CONTROLLERAXISMOTION:
                cout<<evt.caxis.padding1<<" is "<<evt.caxis.value<<" valued\n";
                break;
        }
    }
}

bool JoystickHandler::isConnected()
{
    return m_isJoyConnected;
}