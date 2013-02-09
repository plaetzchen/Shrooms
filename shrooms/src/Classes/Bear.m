//
//  Bear.m
//  Shrooms
//
//  Created by Philip Brechler on 09.02.13.
//
//

#import "Bear.h"

@interface Bear()


@end

@implementation Bear

- (id)init {
    if (self = [super init]) {
//		bear = [[SPImage alloc]initWithContentsOfFile:@"bear.png"];
//        
//        [self addChild:bear];
        
        // all our animation textures are in the atlas
        SPTextureAtlas *atlas = [SPTextureAtlas atlasWithContentsOfFile:@"bear_animated.xml"];
        
        // add frames to movie
        NSArray *frames = [atlas texturesStartingWith:@"bear-pos-"];
        self.bearMoving = [[SPMovieClip alloc] initWithFrames:frames fps:16];
        
        // add sounds
        //SPSound *stepSound = [[SPSound alloc] initWithContentsOfFile:@"step.caf"];
        //[bearMoving setSound:[stepSound createChannel] atIndex:1];
        //[bearMoving setSound:[stepSound createChannel] atIndex:7];
        //[stepSound release];
        
        // move the clip to the center and add it to the stage
        //mMovie.x = CENTER_X - (int)mMovie.width / 2;
        //mMovie.y = CENTER_Y - (int)mMovie.height / 2;
        [self addChild:self.bearMoving];
        [self.bearMoving release];
        


	}
    return self;
}

@end
