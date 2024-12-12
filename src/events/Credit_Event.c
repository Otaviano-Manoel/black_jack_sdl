#include <Credit_Event.h>
#include <Credits_Scene.h>

void Credit_Event_OnClick_Close(GameManager *manager, Object *this)
{
    (void)this;
    manager->sceneManager->layerCurrent = 1;
    Credit_Hide(manager->sceneManager->current);
}