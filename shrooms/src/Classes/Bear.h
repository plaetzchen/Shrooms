//
//  Bear.h
//  Shrooms
//
//  Created by Philip Brechler on 09.02.13.
//
//

#import "SPSprite.h"

@interface Bear : SPSprite {
    SPImage *bear;
    BOOL jumping;
}

@property (nonatomic, retain)     SPMovieClip *bearMoving;

- (void)setRunning:(BOOL)running;
- (void)jump;
@end
