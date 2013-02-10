//
//  LevelGround.h
//  Shrooms
//
//  Created by Philip Brechler on 10.02.13.
//
//

#import "SPSprite.h"

@interface LevelGround : SPSprite {
    SPImage *image1;
    SPImage *image2;
    float mCurStep;
    float mSpeed;
    int currentPart;
    BOOL running;
}

@property (nonatomic, retain)SPImage *groundImage;
@property (nonatomic, retain)NSArray *levelParts;

@property (nonatomic) float mCurStep;

- (id)initWithParts:(NSArray *)parts slots:(NSArray *)slots speed:(float)speed;

@end
