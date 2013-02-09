//
//  Bear.m
//  Shrooms
//
//  Created by Philip Brechler on 09.02.13.
//
//

#import "Bear.h"

@implementation Bear
@synthesize image;

- (id)init {
    if (self = [super init]) {
		image = [[SPImage alloc]initWithContentsOfFile:@"bear.png"];
        
        [self addChild:image];
	}
    return self;
}

- (void)dealloc {
    [image release];
    [super dealloc];
}

@end
