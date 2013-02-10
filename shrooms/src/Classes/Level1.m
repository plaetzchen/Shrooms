//
//  Level1.m
//  Shrooms
//
//  Created by Philip Brechler on 09.02.13.
//
//

#import "Level1.h"
#import "PointInPolygonChecker.h"

@interface Level1()

@property (nonatomic, retain) PointInPolygonChecker* polychecker;

@end

@implementation Level1

float speed = 2.0;

@synthesize collisionPoints;


- (id)init {
    self = [super init];
    if (self){
        forest1 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"forest3.png"] speed:1 direction:BE_PARALLAX_DIRECTION_LEFT];
		[self addChild:forest1 atIndex:0];
        
        forest2 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"forest2.png"] speed:2 direction:BE_PARALLAX_DIRECTION_LEFT];
		[self addChild:forest2 atIndex:1];
        
        forest3 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"forest1.png"] speed:4 direction:BE_PARALLAX_DIRECTION_LEFT];
		[self addChild:forest3 atIndex:2];
        
        SPImage *ground1 = [[SPImage alloc]initWithContentsOfFile:@"level-ground-1.png"];
        SPImage *ground2 = [[SPImage alloc]initWithContentsOfFile:@"level-ground-2.png"];
        SPImage *ground3 = [[SPImage alloc]initWithContentsOfFile:@"level-ground-3.png"];
        SPImage *ground4 = [[SPImage alloc]initWithContentsOfFile:@"level-ground-4.png"];
        SPImage *ground5 = [[SPImage alloc]initWithContentsOfFile:@"level-ground-5.png"];
        SPImage *ground6 = [[SPImage alloc]initWithContentsOfFile:@"level-ground-6.png"];

        
        NSArray *parts = @[ground1,ground2,ground3,ground4,ground5,ground6];
        
       ground = [[LevelGround alloc]initWithParts:parts slots:nil];

        
        ground.y = self.height - ground.height;
        
        bear = [[Bear alloc]init];
        [bear setY:ground.height*0.4];
        [bear setScaleX:0.5f];
        [bear setScaleY:0.5f];
        [ground addChild:bear atIndex:parts.count];
        
        [self addChild:ground atIndex:3];
        

        
        [self addEventListener:@selector(onAddedToStage:) atObject:self forType:SP_EVENT_TYPE_ADDED_TO_STAGE];
        [self addEventListener:@selector(onRemovedFromStage:) atObject:self forType:SP_EVENT_TYPE_REMOVED_FROM_STAGE];
        
        self.collisionPoints = [NSArray arrayWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"level-ground-1" ofType:@"plist"]];
        
        currentPointIndex = 0;
        
        PointInPolygonChecker* polychecker = [[PointInPolygonChecker alloc] initWithArray:self.collisionPoints];
        self.polychecker = polychecker;
        [polychecker release];
        
    }
    
    [self addEventListener:@selector(onEnterFrame:) atObject:self forType:SP_EVENT_TYPE_ENTER_FRAME];
    return self;
}

- (void)onAddedToStage:(SPEvent *)event
{
    [self.stage.juggler addObject:bear.bearMoving];
}

- (void)onRemovedFromStage:(SPEvent *)event
{
    [self.stage.juggler removeObject:bear.bearMoving];
}

- (void)oneFingerTouched {
    [bear setRunning:YES];
    [forest1 start];
}

- (void)swipeUp {
    [bear jump];
    
}

- (void)onEnterFrame:(SPEnterFrameEvent *)event {
    
    NSLog(@"speed: %f",ground.x + self.width);
    if (ground.x + self.width > -ground.x) {
        ground.x -= 2.0f*speed;
        bear.x += 2.0f*speed;
        speed = speed * 1.01;
    } else {
        [bear setRunning:NO];
    }
    
    
    NSDictionary* leftDict = self.collisionPoints[currentPointIndex];
    NSDictionary* rightDict = self.collisionPoints[currentPointIndex+1];
    CGPoint leftPoint = CGPointMake([leftDict[@"x"] floatValue], [leftDict[@"y"] floatValue]);
    CGPoint rightPoint = CGPointMake([rightDict[@"x"] floatValue], [rightDict[@"y"] floatValue]);

    CGPoint currentGrassPoint = CGPointMake(grass.bounds.x*-1,0);
    CGPoint bearFrontFootCheckPoint = CGPointMake(currentGrassPoint.x+bear.x+bear.width, bear.y+bear.height);
    
    CGFloat slope = - ((rightPoint.y-leftPoint.y) / (rightPoint.x-leftPoint.x));
    CGFloat yOffSet = 0;
    if (slope == 0 || slope > 100) {
        yOffSet = leftPoint.y;
    }
    else {
        yOffSet = leftPoint.y / (slope * leftPoint.x);
    }
    CGFloat yCheckPoint = bearFrontFootCheckPoint.x * slope + yOffSet;
    
    SPPoint *checkPoint = [[SPPoint alloc]initWithX:bearFrontFootCheckPoint.x y:bear.y];
//    
//    SPQuad *debugQuad = [[SPQuad alloc] initWithWidth:10 height:10 color:SP_COLOR(arc4random() % 255, arc4random() % 255, arc4random() % 255)];
//    [debugQuad setX:checkPoint.x];
//    [debugQuad setY:checkPoint.y];
//    [grass addChild:debugQuad];
    
    BOOL pointIsInPoly = [self.polychecker checkIfPointInPolygon:checkPoint];
    NSLog(@"pointIsInPoly: %i", pointIsInPoly);
    NSLog(@"Checkpoint: %@",checkPoint.description);
    
//    NSLog(@"slope: %f", slope);
//    NSLog(@"BearFoot: %@", NSStringFromCGPoint(bearFrontFootCheckPoint));
//    
//    CGFloat deltaBearFoot = bearFrontFootCheckPoint.y - checkPoint.y;
//    
//    if (deltaBearFoot < 0){
//        NSLog(@"drüber");
//    } else {
//        NSLog(@"drunter");
//    }
//    if (slope < 100)
//        bear.rotation = slope;
//    else
//        bear.rotation = 0;
    //bear.y = -checkPoint.y;
    if (currentPointIndex+2 == collisionPoints.count){
        currentPointIndex = 0;
    } else if (currentGrassPoint.x >= rightPoint.x){
        currentPointIndex++;
    }
}
@end
