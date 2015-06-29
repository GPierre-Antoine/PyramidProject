//
// Created by Pierre-Antoine on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_GAMEOBJECT_H
#define PYRAMIDPROJECT_GAMEOBJECT_H
namespace nsGameObject
{

    class GameObject
    {


    public:
        virtual void render () = 0;
        virtual ~GameObject () {}
    };

}
#endif //SFMLTEST_GAMEOBJECT_H
