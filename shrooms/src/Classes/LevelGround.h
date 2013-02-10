//
//  LevelGround.h
//  Shrooms
//
//  Created by Philip Brechler on 10.02.13.
//
//

#import "SPSprite.h"

@interface LevelGround : SPSprite

@property (nonatomic, retain)SPImage *groundImage;

- (id)initWithParts:(NSArray *)parts slots:(NSArray *)slots;

@end
