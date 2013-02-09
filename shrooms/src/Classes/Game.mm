//
//  Game.m
//  AppScaffold
//

#import "Game.h" 

#import "GB2ShapeCache.h"

//Pixel to meters ratio. Box2D uses metres as the unit for measurement.
//This ratio defines how many pixels correspond to 1 Box2D "metre"
//Box2D is optimized for objects of 1x1 metre therefore it makes sense
//to define the ratio so that your most common object type is 1x1 metre.
#define PTM_RATIO 32

@implementation Game

- (id)initWithWidth:(float)width height:(float)height
{
    if ((self = [super initWithWidth:width height:height]))
    {
        mContents = [[SPSprite alloc] init];
		mContents.x = 0;
        [mContents setWidth:self.width];
        [mContents setHeight:self.height];
		[self addChild:mContents];
		[mContents release];
        
        [[GB2ShapeCache sharedShapeCache] addShapesWithFile:@"shapedefs.plist"];
        
        // Retrieve screen dimensions
        CGRect screenRect = [[UIScreen mainScreen] bounds];
		CGSize screenSize = CGSizeMake(screenRect.size.width, screenRect.size.height);
        
        //Physics
        
        b2Vec2 gravity;
		gravity.Set(0.0f, -10.0f);
		
		// Do we want to let bodies sleep?
		// This will speed up the physics simulation
		bool doSleep = true;
		
		// Construct a world object, which will hold and simulate the rigid bodies.
		world = new b2World(gravity, doSleep);
		
		world->SetContinuousPhysics(true);
		
		// Debug Draw functions
		m_debugDraw = new GLESDebugDraw( PTM_RATIO );
        
        // Uncomment to enable Box2D debug draw
        //		world->SetDebugDraw(m_debugDraw);
		
        // We have to keep information about screen height because
        // Y-axis direction in Sparrow is reversed compared to Box2D
        // Sparrow (0,0) is top left corner
        // Box2D   (0,0) is bottom left corner
        m_debugDraw->_screenHeight = screenRect.size.height;
        
		uint32 flags = 0;
		flags += b2DebugDraw::e_shapeBit;
        //		flags += b2DebugDraw::e_jointBit;
        //		flags += b2DebugDraw::e_aabbBit;
        //		flags += b2DebugDraw::e_pairBit;
        //		flags += b2DebugDraw::e_centerOfMassBit;
		m_debugDraw->SetFlags(flags);
		
		
		// Define the ground body.
		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(0, 0); // bottom-left corner
		
		// Call the body factory which allocates memory for the ground body
		// from a pool and creates the ground box shape (also from a pool).
		// The body is also added to the world.
		b2Body* groundBody = world->CreateBody(&groundBodyDef);
		
		// Define the ground box shape.
		b2PolygonShape groundBox;
		
		// bottom
		groundBox.SetAsEdge(b2Vec2(0,0), b2Vec2(screenSize.width/PTM_RATIO,0));
		groundBody->CreateFixture(&groundBox,0);
		
		// top
        groundBox.SetAsEdge(b2Vec2(0,screenSize.height/PTM_RATIO), b2Vec2(screenSize.width/PTM_RATIO,screenSize.height/PTM_RATIO));
        groundBody->CreateFixture(&groundBox,0);
		
		// left
		groundBox.SetAsEdge(b2Vec2(0,screenSize.height/PTM_RATIO), b2Vec2(0,0));
		groundBody->CreateFixture(&groundBox,0);
		
		// right
		groundBox.SetAsEdge(b2Vec2(screenSize.width/PTM_RATIO,screenSize.height/PTM_RATIO), b2Vec2(screenSize.width/PTM_RATIO,0));
		groundBody->CreateFixture(&groundBox,0);
        
//		sky = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"sky.png"]
//                                                    speed:0.4
//                                                direction:BE_PARALLAX_DIRECTION_LEFT];
//		[mContents addChild:sky];
		forest1 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"bg.png"] speed:1 direction:BE_PARALLAX_DIRECTION_LEFT];
		[mContents addChild:forest1];

        
//		forest2 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"mountainsfront.png"]
//                                                           speed:4
//                                                       direction:BE_PARALLAX_DIRECTION_LEFT];
//		[mContents addChild:forest2];
//        
//        forest3 = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"mountainsfront.png"]
//                                                        speed:4
//                                                    direction:BE_PARALLAX_DIRECTION_LEFT];
//		[mContents addChild:forest3];
//        
//		grass = [BEParallaxSprite parallexSpriteWithTexture:[SPTexture textureWithContentsOfFile:@"grass.png"]
//                                                      speed:10
//                                                  direction:BE_PARALLAX_DIRECTION_LEFT];
//		grass.y = 320-grass.height;
//		[mContents addChild:grass];
        
        bear = [[Bear alloc]init];
        [bear setY:self.height*0.6];
        [self addChild:bear];
        
        [self setAnchorPoint:[[GB2ShapeCache sharedShapeCache] anchorPointForShape:@"bear"]
                    forImage:bear.image];

        [self addChild:bear];
        
        // Create physics body
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        
        // Remember that Y-axis directions in Sparrow and Box2D are opposite
        bodyDef.position.Set(bear.x/PTM_RATIO, (m_debugDraw->_screenHeight-bear.y)/PTM_RATIO);
        bodyDef.userData = bear;
        b2Body *body = world->CreateBody(&bodyDef);
        
        // Add the fixture definitions to the body
        [[GB2ShapeCache sharedShapeCache] addFixturesToBody:body forShapeName:@"bear"];

        
    }
    return self;
}

- (b2Body *)bodyTouchedAtPoint:(CGPoint)point
{
    // pixels -> meters
    point.x /= PTM_RATIO;
    point.y = (m_debugDraw->_screenHeight - point.y)/PTM_RATIO;
    
    // Each next object (body) in physics world
    for (b2Body *b = world->GetBodyList(); b; b = b->GetNext()) {
        // Ignore static objects (edges of the screen)
        if (b->GetType() != b2_staticBody) {
            // Each next fixture in body
            for (b2Fixture *f = b->GetFixtureList(); f; f = f->GetNext()) {
                // Any touch on fixture?
                if (f->TestPoint(b2Vec2(point.x, point.y))) {
                    // Yes, there was a touch so we return this object (body)
                    return b;
                }
            }
        }
    }
    
    // No object was touched
    return nil;
}

-(void)render:(SPRenderSupport *)support
{
    // At first we have to draw Sparrow objects and then Box2D debug shapes.
    // This is because Sparrow clears the entire screen before drawing.
    // We will lost Box2D debug shapes if we draw them before Sparrow objects.
    [super render:support];
    
	// Needed states:  GL_VERTEX_ARRAY,
	// Unneeded states: GL_TEXTURE_2D, GL_COLOR_ARRAY, GL_TEXTURE_COORD_ARRAY
    glEnableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    
	world->DrawDebugData();
    
	// restore default GL states
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    
}

- (void)setAnchorPoint:(CGPoint)point forImage:(SPImage *)image
{
    // Anchor point coords are float values in range 0 - 1 thus we have to change them to pixel units
    point.x = image.width * point.x;
    
    // In PhysicsEditor point (0,0) is equal to bottom-left corner.
    // In Sparrow point (0,0) is equal to top-left corner.
    // We have to calculate Y-axis position a bit different than X-axis position
    point.y = image.height - (image.height * point.y);
    
    // Translate SPImage object to fit anchor point
    image.x = -point.x;
    image.y = -point.y;
}

//-(void)advanceTime:(double)seconds
//{
//	//It is recommended that a fixed time step is used with Box2D for stability
//	//of the simulation, however, we are using a variable time step here.
//	//You need to make an informed choice, the following URL is useful
//	//http://gafferongames.com/game-physics/fix-your-timestep/
//	
//	int32 velocityIterations = 8;
//	int32 positionIterations = 1;
//	
//	// Instruct the world to perform a single step of simulation. It is
//	// generally best to keep the time step and iterations fixed.
//	world->Step(seconds, velocityIterations, positionIterations);
//    
//	
//	//Iterate over the bodies in the physics world
//	for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
//	{
//		if (b->GetUserData() != NULL)
//		{
//			SPSprite *myActor = (SPSprite*)b->GetUserData();
//            myActor.x = b->GetPosition().x * PTM_RATIO;
//            // Remember that Y-axis directions in Sparrow and Box2D are opposite
//			myActor.y = m_debugDraw->_screenHeight - b->GetPosition().y * PTM_RATIO;
//			myActor.rotation = -1 * b->GetAngle();
//		}
//	}
//}


- (void)oneFingerTouch {
    [forest1 stop];
}

- (void)swipeUp {
    [forest1 start];
}

@end
