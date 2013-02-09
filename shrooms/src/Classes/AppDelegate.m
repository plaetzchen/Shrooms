//
//  AppScaffoldAppDelegate.m
//  AppScaffold
//

#import "AppDelegate.h"
#import "Game.h" 

@implementation AppDelegate

- (id)init
{
    if ((self = [super init]))
    {
        UIViewController *rootViewController = [[UIViewController alloc]init];
        mWindow = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
        mSparrowView = [[SPView alloc] initWithFrame:mWindow.bounds];
        mSparrowView.multipleTouchEnabled = YES;
        mSparrowView.exclusiveTouch = YES;
        [rootViewController.view addSubview:mSparrowView];
        mWindow.rootViewController = rootViewController;
    }
    return self;
}

- (void)applicationDidFinishLaunching:(UIApplication *)application 
{   
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    
    [SPStage setSupportHighResolutions:YES];
    [SPAudioEngine start];
    
    Game *game = [[Game alloc] init];        
    mSparrowView.stage = game;
    mSparrowView.frameRate = 30.0f;
    [game release];
    
    [mWindow makeKeyAndVisible];
    [mSparrowView start];
    
    UITapGestureRecognizer *oneFingerRecognizer = [[UITapGestureRecognizer alloc]initWithTarget:mSparrowView.stage action:@selector(oneFingerTouch)];
    [oneFingerRecognizer setNumberOfTouchesRequired:1];
    
    UISwipeGestureRecognizer *swipeUpRecognizer = [[UISwipeGestureRecognizer alloc]initWithTarget:mSparrowView.stage action:@selector(swipeUp)];
    [swipeUpRecognizer setDirection:UISwipeGestureRecognizerDirectionUp];

    [mSparrowView addGestureRecognizer:oneFingerRecognizer];
    [mSparrowView addGestureRecognizer:swipeUpRecognizer];
    
    [pool release];
}

- (void)applicationWillResignActive:(UIApplication *)application 
{    
    [mSparrowView stop];
}

- (void)applicationDidBecomeActive:(UIApplication *)application 
{
	[mSparrowView start];
}

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application
{
    [SPPoint purgePool];
    [SPRectangle purgePool];
    [SPMatrix purgePool];    
}

- (void)dealloc 
{
    [SPAudioEngine stop];
    [mSparrowView release];
    [mWindow release];    
    [super dealloc];
}

@end
