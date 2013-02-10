//
//  Level1.h
//  Shrooms
//
//  Created by Philip Brechler on 09.02.13.
//
//

#import "Scene.h"
#import "BEParallaxSprite.h"
#import "Bear.h"
#import "LevelGround.h"

@interface Level1 : Scene {
    BEParallaxSprite *sky;
    BEParallaxSprite *forest1;
    BEParallaxSprite *forest2;
    BEParallaxSprite *forest3;
    BEParallaxSprite *grass;
    Bear *bear;
    LevelGround *ground;
    NSArray *collisionPoints;
    NSUInteger currentPointIndex;
}

@property (nonatomic, retain) NSArray *collisionPoints;

@end
