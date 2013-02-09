//
//  AppScaffoldAppDelegate.m
//  AppScaffold
//

#import "AppDelegate.h"
#import "Game.h" 

#import <netmera/netmera.h>

@implementation AppDelegate

- (id)init
{
    if ((self = [super init]))
    {
        UIViewController *rootViewController = [[UIViewController alloc]init];
        mWindow = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
        mSparrowView = [[SPView alloc] initWithFrame:CGRectMake(0, 0, mWindow.frame.size.height, mWindow.frame.size.width)];
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
    
    Game *game = [[Game alloc] initWithWidth:mSparrowView.frame.size.width height:mSparrowView.frame.size.height];
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
    
    [self netmeraSetup];
    
    [pool release];
}

-(void) netmeraSetup
{
    
    // Netmera setup
    [NetmeraClient initWithApiKey:@"WVhCd1ZYSnNQV2gwZEhBbE0wRWxNa1lsTWtZMU1qRTJPRGM1TWk1dVpYUnRaWEpoTG1OdmJTVXpRVGd3SlRKR2JXOWlhVzFsY21FbE1rWm5ZV1JuWlhRbE1rWjBkWFJ2Y21saGJDNTRiV3dtYm0xVGFYUmxWWEpzUFdoMGRIQWxNMEVsTWtZbE1rWTFNakUyT0RjNU1pNXVaWFJ0WlhKaExtTnZiU1V6UVRnd0ptMXZaSFZzWlVsa1BURXhOakF6Sm1Gd2NFbGtQVFV5TVRZNE56a3lKbTV0VkdWdGNHeGhkR1U5Ylc5aWFYUmxiWEJzWVhSbEptOTNibVZ5U1dROVltVnRlV0Z3Y0Naa2IyMWhhVzQ5Ym1WMGJXVnlZUzVqYjIwbWJtMVRhWFJsUFRVeU1UWTROemt5Sm05M2JtVnlVbTlzWlZSNWNHVTlNU1oyYVdWM1pYSlNiMnhsVkhsd1pUMHhKblpwWlhkbGNrbGtQV0psYlhsaGNIQW0"];
    
    NetmeraContent *content = [[NetmeraContent alloc]initWithObjectName:@"BeMyApp2013"];
    [content add:@"email" object:@"xoxo@zutrinken.com"];
    [content add:@"name" object:@"Peter"];
    [content add:@"surname" object:@"Amende"];
    [content add:@"projectname" object:@"Shrooms"];
    [content createInBackground];

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
