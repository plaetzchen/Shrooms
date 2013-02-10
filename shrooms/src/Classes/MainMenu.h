//
//  MainMenu.h
//  Shrooms
//
//  Created by Philip Brechler on 10.02.13.
//
//

#import "Scene.h"
#import "BEParallaxSprite.h"

@interface MainMenu : Scene {
    BEParallaxSprite *sky;
    BEParallaxSprite *forest1;
    BEParallaxSprite *forest2;
    BEParallaxSprite *forest3;
    BEParallaxSprite *forest4;
    BEParallaxSprite *grass;
    SPImage *startButton;
    SPImage *highscoreButton;
    SPImage *credits;
}

@end
