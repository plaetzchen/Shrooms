/**
 * Copyright 2012 Inomera Research
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "Netmera.h"
#import "SA_OAuthTwitterEngine.h"
#import "SA_OAuthTwitterController.h"

@class SA_OAuthTwitterEngine;

/**
 NetmeraTwitterUtils object uses Twitter
 account for user operations.
 */
@interface NetmeraTwitterUtils : NSObject <SA_OAuthTwitterControllerDelegate>{
    SA_OAuthTwitterEngine *_engine;
    id _target;
    void (^_block)(NetmeraUser *user, NSError *error);
}

/**
 Creates NetmeraTwitterUtils to call login and logOut methods. Netmera prefers to use IOS5 twitter sdk or MGTwitterEngine framework for older versions of IOS5. You can check MGTwitterEngine guide from http://www.icodeblog.com/2010/09/16/dealing-with-the-twitter-oauth-apocalypse/
 
 @param consumerKey You Twitter App key. Leave it nil if your target is IOS5 or newer
 @param consumerSecret You Twitter App secret. Leave it nil if your target is IOS5 or newer
 */
- (NetmeraTwitterUtils *) initWithTwitterConsumerKey:(NSString *) consumerKey andTwitterConsumerSecret:(NSString *) consumerSecret;

/**
 Logs a user into the registered application with Twitter account.
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackRegisterWithNetmeraUser:(NetmeraUser *)user error:(NSError *)error
 */
-(void)logInInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Logs a user into the registered application with Twitter account.
 @param block The block to execute. The block should have the following argument signature: (NetmeraUser *user, NSError *error)
 */
-(void) logInInBackgroundWithViewController:(UIViewController *)rootViewController withBlock:(void(^)(NetmeraUser *user, NSError *error))block;

/**
 Twitter user logged out from the application.
 */
+(void) logOut;

@end
