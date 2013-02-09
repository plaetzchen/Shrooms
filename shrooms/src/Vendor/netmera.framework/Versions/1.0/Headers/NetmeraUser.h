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

/**
 NetmeraUser object is for managing users of the application. You can
 register, update, login users with this class.
 */
@interface NetmeraUser : NSObject{
    
    NSString *email;
    NSString *password;
    NSString *nickname;
    NSString *name;
    NSString *surname;
    NSString *facebookId;
    NSString *twitterUserName;
    BOOL isNewUser;
    BOOL isGeneratedMail;
    
}

@property (nonatomic, retain) NSString *email;
@property (nonatomic, retain) NSString *password;
@property (nonatomic, retain) NSString *nickname;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *surname;
@property (nonatomic, retain) NSString *facebookId;
@property (nonatomic, retain) NSString *twitterUserName;
@property BOOL isNewUser;
@property BOOL isGeneratedMail;

/**
 Returns the current logged user. If no user logged in then it returns nil.
 
 @return current user
 */

+(NetmeraUser *) getCurrentUser;

/**
 Registers new user. Before calling this method email,password and
 nickname fields of the NetmeraUser should be setted. Those are
 the compulsory fields. There are also optional name and surname fields.
 
 <br>
 <br>
 
 <code>
 NetmeraUser *user = [[NetmeraUser alloc] init];<br>
 user.email = @"test@test.com";<br>
 user.password = @"12345";<br>
 user.nickname = @"test";<br>
 NSError *err = nil;<br>
 BOOL isregistered = [user registerWithError:&err];<br>
 </code>
 
 @param error if it cannot access server
 */
-(BOOL) registerWithError:(NSError **)error;


/**
 Registers new user. Before calling this method email,password and
 nickname fields of the NetmeraUser should be setted. Those are
 the compulsory fields. There are also optional name and surname fields.
 
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackRegisterWithError:(NSError *)error. error will be nil on success and set if there was an error.
 
 */
-(void)registerInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Registers new user in the background thread and executes the given callback block. Before calling this method email,password and
 nickname fields of the NetmeraUser should be setted. Those are
 the compulsory fields. There are also optional name and surname fields.
 
 
 @param block The block to execute. The block should have the following argument signature: (NSError *error)
 
 */
-(void)registerInBackgroundWithBlock:(void(^)(NSError *error))block;

/**
 Updates user info. Before calling this method email,password and nickname
 fields of the NetmeraUser should be setted. Those are the
 compulsory fields.
 
 @param error if it cannot access server
 */
-(BOOL) update:(NSError **)error;

/**
 Updates user info. Before calling this method email,password and nickname
 fields of the NetmeraUser should be setted. Those are the
 compulsory fields.
 
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackUpdateWithError:(NSError *)error. error will be nil on success and set if there was an error.
 
 */
- (void)updateInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Updates user info. Before calling this method email,password and nickname
 fields of the NetmeraUser should be setted. Those are the
 compulsory fields.
 
 @param block The block to execute. The block should have the following argument signature: (NSError *error)
 
 */
-(void)updateInBackgroundWithBlock:(void(^)(NSError *error))block;

/**
 Logs a user into the registered application. Email and password fields of
 user is used for this operation.
 
 @param email of the user
 @param password of the user
 @param error if it cannot access server
 @return the logged User
 */
+(NetmeraUser *) loginWithEmail:(NSString *)email andPassword:(NSString *)password withError:(NSError **)error;

/**
 Logs a user into the registered application. Email and password fields of user is used for this operation.
 
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackLoginWithError:(NSError *)error withNetmeraUser:(NetmeraUser *)user. error will be nil on success and set if there was an error.
 
 @param email of the user
 @param password of the user
 */
+(void)loginInBackgroundWithTarget:(id)target selector:(SEL)selector withEmail:(NSString *)email andPassword:(NSString *)password;

+(NetmeraUser *) loginByFacebook:(NSString *)facebookId nickname:(NSString *)nickname email:(NSString *)email password:(NSString *)password name:(NSString *)name surname:(NSString *)surname error:(NSError **)error;

+(NetmeraUser *) loginBySocialWithFacebookId:(NSString *)facebookId orTwitterUserName:(NSString *)userName nickname:(NSString *)nickname email:(NSString *)email password:(NSString *)password name:(NSString *)name surname:(NSString *)surname error:(NSError **)error;

+(NetmeraUser *) loginWithFacebookId:(NSString *)facebookId withError:(NSError **)error;

/**
 User logged out from the application.
 */
+(void) logout;

/**
 Activates the registered User.
 
 @param email of the user
 @param error if it cannot access server
 */
-(BOOL) activateUserWithEmail:(NSString *)email andError:(NSError **)error;

/**
 Deactivates the registered User
 
 @param email of the user
 @param error if it cannot access server
 */
-(BOOL) deactivateUserWithEmail:(NSString *)email andError:(NSError **)error;

@end