//
//  Bear.m
//  Shrooms
//
//  Created by Philip Brechler on 09.02.13.
//
//

#import "Bear.h"

@implementation Bear

- (id)init {
    if (self = [super init]) {
		bear = [[SPImage alloc]initWithContentsOfFile:@"bear.png"];
        
        [self addChild:bear];
	}
    return self;
}

@end
