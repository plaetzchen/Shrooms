//
//  Game.h
//  AppScaffold
//

#import <Foundation/Foundation.h>
#import "BEParallaxSprite.h"
#import "Scene.h"

@interface Game : SPStage {

    SPSprite *mContents;
    Scene *currentScene;
    SPSoundChannel *mMusicChannel;
}



@end
