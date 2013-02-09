//
//  Game.h
//  AppScaffold
//

#import <Foundation/Foundation.h>
#import "BEParallaxSprite.h"
#import "Box2D.h"
#import "GLES-Render.h"
#import "Bear.h"

@interface Game : SPStage {
    BEParallaxSprite *sky;
    BEParallaxSprite *forest1;
    BEParallaxSprite *forest2;
    BEParallaxSprite *forest3;
    BEParallaxSprite *grass;
    SPSprite *mContents;
    Bear *bear;
    b2World* world;
    GLESDebugDraw *m_debugDraw;
}

@end
