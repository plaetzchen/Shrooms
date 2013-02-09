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
 NetmeraFacebookUtils object uses Facebook
 account for user operations.
 */
@interface NetmeraFacebookUtils : NSObject

/**
 Facebook user logged out from the application.
 */
+(void) logOut;

/**
 Set your Facebook App ID  in the app delegate to Netmera
 */
+(void) setFacebookAppId:(NSString *)appId;

/**
 Logs a user into the registered application with Facebook account without Facebook permissions.
 @param block The block to execute. The block should have the following argument signature: (NetmeraUser *user, NSError *error)
 */
+(void) logInWithBlock:(void(^)(NetmeraUser *user, NSError *error))block;

/**
 Logs a user into the registered application with Facebook account without Facebook permissions.
 
 @param appId Your Facebook App ID
 @param block The block to execute. The block should have the following argument signature: (NetmeraUser *user, NSError *error)
 */
+(void) logInWithFacebookAppId:(NSString *)appId withBlock:(void(^)(NetmeraUser *user, NSError *error))block;

/**
 Logs a user into the registered application with Facebook account wit Facebook permissions.
 
 @param permissions Permission array that you want to reach user details from his/her facebook account
 @param block The block to execute. The block should have the following argument signature: (NetmeraUser *user, NSError *error)
 */
+(void) logInWithPermissions:(NSArray *)permissions withBlock:(void(^)(NetmeraUser *user, NSError *error))block;

/**
 Logs a user into the registered application with Facebook account with Facebook permissions.
 
 @param permissions Permission array that you want to reach user details from his/her facebook account
 @param appId Your Facebook App ID
 @param block The block to execute. The block should have the following argument signature: (NetmeraUser *user, NSError *error)
 */
+(void) logInWithPermissions:(NSArray *)permissions withFacebookAppId:(NSString *)appId withBlock:(void(^)(NetmeraUser *user, NSError *error))block;

/**
 Logs a user into the registered application with Facebook account without Facebook permissions.
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackRegisterWithNetmeraUser:(NetmeraUser *)user error:(NSError *)error
 */
+(void)logInInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Logs a user into the registered application with Facebook account without Facebook permissions.
 
 @param appId Your Facebook App ID
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackRegisterWithNetmeraUser:(NetmeraUser *)user error:(NSError *)error
 */
+(void)logInInBackgroundWithTarget:(id)target selector:(SEL)selector withFacebookAppId:(NSString *)appId;

/**
 Logs a user into the registered application with Facebook account wit Facebook permissions.
 
 @param permissions Permission array that you want to reach user details from his/her facebook account
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackRegisterWithNetmeraUser:(NetmeraUser *)user error:(NSError *)error
 */
+(void)logInInBackgroundWithTarget:(id)target selector:(SEL)selector withPermissions:(NSArray *)permissions;

/**
 Logs a user into the registered application with Facebook account with Facebook permissions.
 
 @param permissions Permission array that you want to reach user details from his/her facebook account
 @param appId Your Facebook App ID
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackRegisterWithNetmeraUser:(NetmeraUser *)user error:(NSError *)error
 */
+(void)logInInBackgroundWithTarget:(id)target selector:(SEL)selector withPermissions:(NSArray *)permissions withFacebookAppId:(NSString *)appId;

////

/** facebook permission key constant for "user_about_me" */
extern NSString * const facebook_permission_user_about_me;
/** facebook permission key constant for "friends_about_me" */
extern NSString * const facebook_permission_friends_about_me;

//Provides access to the user's list of activities as the activities connection
/** facebook permission key constant for "user_activities" */
extern NSString * const facebook_permission_user_activities;
/** facebook permission key constant for "friends_activities" */
extern NSString * const facebook_permission_friends_activities;

//Provides access to the birthday with year as the birthday property
/** facebook permission key constant for "user_birthday" */
extern NSString * const facebook_permission_user_birthday;
/** facebook permission key constant for "friends_birthday" */
extern NSString * const facebook_permission_friends_birthday;

//Provides read access to the authorized user's check-ins or a friend's check-ins that the user can see. This permission is superseded by user_status for new applications as of March, 2012.
/** facebook permission key constant for "user_checkins" */
extern NSString * const facebook_permission_user_checkins;
/** facebook permission key constant for "friends_checkins" */
extern NSString * const facebook_permission_friends_checkins;

//Provides access to education history as the education property
/** facebook permission key constant for "user_education_history" */
extern NSString * const facebook_permission_user_education_history;
/** facebook permission key constant for "friends_education_history" */
extern NSString * const facebook_permission_friends_education_history;

//Provides access to the list of events the user is attending as the events connection
/** facebook permission key constant for "user_events" */
extern NSString * const facebook_permission_user_events;
/** facebook permission key constant for "friends_events" */
extern NSString * const facebook_permission_friends_events;

//Provides access to the list of groups the user is a member of as the groups connection
/** facebook permission key constant for "user_groups" */
extern NSString * const facebook_permission_user_groups;
/** facebook permission key constant for "friends_groups" */
extern NSString * const facebook_permission_friends_groups;

//Provides access to the user's hometown in the hometown property
/** facebook permission key constant for "user_hometown" */
extern NSString * const facebook_permission_user_hometown;
/** facebook permission key constant for "friends_hometown" */
extern NSString * const facebook_permission_friends_hometown;

//Provides access to the user's list of interests as the interests connection
/** facebook permission key constant for "user_interests" */
extern NSString * const facebook_permission_user_interests;
/** facebook permission key constant for "friends_interests" */
extern NSString * const facebook_permission_friends_interests;

//Provides access to the list of all of the pages the user has liked as the likes connection
/** facebook permission key constant for "user_likes" */
extern NSString * const facebook_permission_user_likes;
/** facebook permission key constant for "friends_likes" */
extern NSString * const facebook_permission_friends_likes;

//Provides access to the user's current location as the location property
/** facebook permission key constant for "user_location" */
extern NSString * const facebook_permission_user_location;
/** facebook permission key constant for "friends_location" */
extern NSString * const facebook_permission_friends_location;

//Provides access to the user's notes as the notes connection
/** facebook permission key constant for "user_notes" */
extern NSString * const facebook_permission_user_notes;
/** facebook permission key constant for "friends_notes" */
extern NSString * const facebook_permission_friends_notes;

//Provides access to the photos the user has uploaded, and photos the user has been tagged in
/** facebook permission key constant for "user_photos" */
extern NSString * const facebook_permission_user_photos;
/** facebook permission key constant for "friends_photos" */
extern NSString * const facebook_permission_friends_photos;

//Provides access to the questions the user or friend has asked
/** facebook permission key constant for "user_questions" */
extern NSString * const facebook_permission_user_questions;
/** facebook permission key constant for "friends_questions" */
extern NSString * const facebook_permission_friends_questions;

//Provides access to the user's family and personal relationships and relationship status
/** facebook permission key constant for "user_relationships" */
extern NSString * const facebook_permission_user_relationships;
/** facebook permission key constant for "friends_relationships" */
extern NSString * const facebook_permission_friends_relationships;

//Provides access to the user's relationship preferences
/** facebook permission key constant for "user_relationship_details" */
extern NSString * const facebook_permission_user_relationship_details;
/** facebook permission key constant for "friends_relationship_details" */
extern NSString * const facebook_permission_friends_relationship_details;

//Provides access to the user's religious and political affiliations
/** facebook permission key constant for "user_religion_politics" */
extern NSString * const facebook_permission_user_religion_politics;
/** facebook permission key constant for "friends_religion_politics" */
extern NSString * const facebook_permission_friends_religion_politics;

//Provides access to the user's status messages and checkins. Please see the documentation for the location_post table for information on how this permission may affect retrieval of information about the locations associated with posts.
/** facebook permission key constant for "friends_status" */
extern NSString * const facebook_permission_user_status;
/** facebook permission key constant for "friends_status" */
extern NSString * const facebook_permission_friends_status;

//Provides access to the user's subscribers and subscribees
/** facebook permission key constant for "user_subscriptions" */
extern NSString * const facebook_permission_user_subscriptions;
/** facebook permission key constant for "friends_subscriptions" */
extern NSString * const facebook_permission_friends_subscriptions;

//Provides access to the videos the user has uploaded, and videos the user has been tagged in
/** facebook permission key constant for "user_videos" */
extern NSString * const facebook_permission_user_videos;
/** facebook permission key constant for "friends_videos" */
extern NSString * const facebook_permission_friends_videos;

//Provides access to the user's web site URL
/** facebook permission key constant for "user_website" */
extern NSString * const facebook_permission_user_website;
/** facebook permission key constant for "friends_website" */
extern NSString * const facebook_permission_friends_website;

//Provides access to work history as the work property
/** facebook permission key constant for "user_work_history" */
extern NSString * const facebook_permission_user_work_history;
/** facebook permission key constant for "friends_work_history" */
extern NSString * const facebook_permission_friends_work_history;

//Provides access to the user's primary email address in the email property. Do not spam users. Your use of email must comply both with Facebook policies and with the CAN-SPAM Act.
/** facebook permission key constant for "email" */
extern NSString * const facebook_permission_email;

//Enables your application to retrieve access_tokens for Pages and Applications that the user administrates. The access tokens can be queried by calling /<user_id>/accounts via the Graph API. See here for generating long-lived Page access tokens that do not expire after 60 days.
/** facebook permission key constant for "manage_pages" */
extern NSString * const facebook_permission_manage_pages;

//Allows your app to publish to the Open Graph using Built-in Actions, Achievements, Scores, or Custom Actions. Your app can also publish other activity which is detailed in the Publishing Permissions doc. Note: The user-prompt for this permission will be displayed in the first screen of the Enhanced Auth Dialog and cannot be revoked as part of the authentication flow. However, a user can later revoke this permission in their Account Settings. If you want to be notified if this happens, you should subscribe to the permissions object within the Realtime API.
/** facebook permission key constant for "publish_actions" */
extern NSString * const facebook_permission_publish_actions;

//Allows you post and retrieve game achievement activity.
/** facebook permission key constant for "user_games_activity" */
extern NSString * const facebook_permission_user_games_activity;
/** facebook permission key constant for "friends_games_activity" */
extern NSString * const facebook_permission_friends_games_activity;

//Provides access to any friend lists the user created. All user's friends are provided as part of basic data, this extended permission grants access to the lists of friends a user has created, and should only be requested if your application utilizes lists of friends.
/** facebook permission key constant for "read_friendlists" */
extern NSString * const facebook_permission_read_friendlists;

//	Provides read access to the Insights data for pages, applications, and domains the user owns.
/** facebook permission key constant for "read_insights" */
extern NSString * const facebook_permission_read_insights;

//	Provides the ability to read from a user's Facebook Inbox.
/** facebook permission key constant for "read_mailbox" */
extern NSString * const facebook_permission_read_mailbox;

//Provides read access to the user's friend requests
/** facebook permission key constant for "read_requests" */
extern NSString * const facebook_permission_read_requests;

//Provides access to all the posts in the user's News Feed and enables your application to perform searches against the user's News Feed
/** facebook permission key constant for "read_stream" */
extern NSString * const facebook_permission_read_stream;

//Provides applications that integrate with Facebook Chat the ability to log in users.
/** facebook permission key constant for "xmpp_login" */
extern NSString * const facebook_permission_xmpp_login;

//	Provides the ability to manage ads and call the Facebook Ads API on behalf of a user.
/** facebook permission key constant for "ads_management" */
extern NSString * const facebook_permission_ads_management;

//	Enables your application to create and modify events on the user's behalf
/** facebook permission key constant for "create_event" */
extern NSString * const facebook_permission_create_event;

//	Enables your app to create and edit the user's friend lists.
/** facebook permission key constant for "manage_friendlists" */
extern NSString * const facebook_permission_manage_friendlists;

//	Enables your app to read notifications and mark them as read. Intended usage: This permission should be used to let users read and act on their notifications; it should not be used to for the purposes of modeling user behavior or data mining. Apps that misuse this permission may be banned from requesting it.
/** facebook permission key constant for "manage_notifications" */
extern NSString * const facebook_permission_manage_notifications;

//	Provides access to the user's online/offline presence
/** facebook permission key constant for "user_online_presence" */
extern NSString * const facebook_permission_user_online_presence;

//	Provides access to the user's friend's online/offline presence
/** facebook permission key constant for "friends_online_presence" */
extern NSString * const facebook_permission_friends_online_presence;

//	Enables your app to perform checkins on behalf of the user.
/** facebook permission key constant for "publish_checkins" */
extern NSString * const facebook_permission_publish_checkins;

//	Enables your app to post content, comments, and likes to a user's stream and to the streams of the user's friends. This is a superset publishing permission which also includes publish_actions. However, please note that Facebook recommends a user-initiated sharing model. Please read the Platform Policies to ensure you understand how to properly use this permission. Note, you do not need to request the publish_stream permission in order to use the Feed Dialog, the Requests Dialog or the Send Dialog.
/** facebook permission key constant for "publish_stream" */
extern NSString * const facebook_permission_publish_stream;

//	Enables your application to RSVP to events on the user's behalf
/** facebook permission key constant for "rsvp_event" */
extern NSString * const facebook_permission_rsvp_event;

@end