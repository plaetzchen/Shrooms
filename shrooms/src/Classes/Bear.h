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
}
@property (nonatomic, retain)     SPMovieClip *bearMoving;

- (void)setRunning:(BOOL)running;

@end
