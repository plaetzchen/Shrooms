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
 This is the main class to manage push notifications in Netmera. With the help
 of this class, you can register/unregister devices to get notification.
 */
@interface NetmeraPushService : NSObject

/**
 Sends notification to IOs and Android devices.
 
 @param message Body text of push notification
 @param error if it cannot access server
 @return NSMutableDictionary include max. two NetmeraPushInfo object with keys "IOS" and "Android"
 */
+(NSMutableDictionary *) sendNotificationWithMessage:(NSString *)message withError:(NSError **)error;

/**
 Sends notification to IOs and Android devices.
 
 @param message Body text of push notification
 @param deviceGroups Names of your target group
 @param error if it cannot access server
 @return NSMutableDictionary include max. two NetmeraPushInfo object with keys "IOS" and "Android"
 */
+(NSMutableDictionary *) sendNotificationWithMessage:(NSString *)message withDeviceGroups:(NSArray *)deviceGroups withError:(NSError **)error;

/**
 Sends notification to IOs and Android devices.
 
 @param message Body text of push notification
 @param deviceGroups Names of your target group
 @param isSendToIOS BOOL parameter if you want to send your push notification to IOs devices
 @param isSendToAndroid BOOL parameter if you want to send your push notification to Android devices
 @param error if it cannot access server
 @return NSMutableDictionary include max. two NetmeraPushInfo object with keys "IOS" and "Android"
 */
+(NSMutableDictionary *) sendNotificationWithMessage:(NSString *)message withDeviceGroups:(NSArray *)deviceGroups isSendToIOS:(BOOL)isSendToIOS isSendToAndroid:(BOOL)isSendToAndroid withError:(NSError **)error;

/**
 Sends notification to IOs and Android devices in backgroud thread.
 
 @param message Body text of push notification
 */
+(void) sendNotificationInBackgroundWithMessage:(NSString *)message;

/**
 Sends notification to IOs and Android devices in backgroud thread.
 
 @param message Body text of push notification
 @param deviceGroups Names of your target group
 @param isSendToIOS BOOL parameter if you want to send your push notification to IOs devices
 @param isSendToAndroid BOOL parameter if you want to send your push notification to Android devices
 */
+(void) sendNotificationInBackgroundWithMessage:(NSString *)message withDeviceGroups:(NSArray *)deviceGroups isSendToIOS:(BOOL)isSendToIOS isSendToAndroid:(BOOL)isSendToAndroid;

/**
 Sends notification to IOs and Android devices in backgroud thread.
 
 @param block The block to execute. The block should have the following argument signature: (NSError *error, NSMutableDictionary *pushInfoList)
 @param message Body text of push notification
 @param deviceGroups Names of your target group
 @param isSendToIOS BOOL parameter if you want to send your push notification to IOs devices
 @param isSendToAndroid BOOL parameter if you want to send your push notification to Android devices
 */
+(void) sendNotificationInBackgroundWithBlock:(void(^)(NSError *error, NSMutableDictionary *pushInfoList))block withMessage:(NSString *)message withDeviceGroups:(NSArray *)deviceGroups isSendToIOS:(BOOL)isSendToIOS isSendToAndroid:(BOOL)isSendToAndroid withError:(NSError **)error;
/**
 Unregisters device.
 @param token application's deviceToken
 */
+(void) unRegisterWithToken:(NSString *)token;

/**
 Unregisters device in the background thread and not callback any
 @param token application's deviceToken
 
 */
+(void) unRegisterInBackgroundWithToken:(NSString *)token;

/**
 Unregisters device in the background thread
 
 @param token application's deviceToken
 @param block The block to execute. The block should have the following argument signature: (NSError *error)
 */
+(void) unRegisterInBackgroundWithToken:(NSString *)token withBlock:(void(^)(NSError *error))block;

/**
 Registers the device into to the server.
 
 @param token application's deviceToken
 */
+(void) registerWithToken:(NSString *)token;

/**
 Registers the device into to the server in the background thread and not callback any
 @param token application's deviceToken
 
 */
+(void) registerInBackgroundWithToken:(NSString *)token;

/**
 Unregisters device in the background thread
 
 @param token application's deviceToken
 @param block The block to execute. The block should have the following argument signature: (NSError *error)
 */
+(void) registerInBackgroundWithToken:(NSString *)token withBlock:(void(^)(NSError *error))block __attribute__((deprecated));

/**
 Gets all groups of your application's token list
 
 @param error if it cannot access server
 */
+(NSArray *)getNetmeraDeviceGroupsWithError:(NSError **)error;

/**
 Unregister any device from any groups.
 
 @param deviceDetail token and deviceGroupList attributes of NetmeraDeviceDetail instance that you created must not be nil.
 */
+(void) unRegisterWithNetmeraDeviceDetail:(NetmeraDeviceDetail *)deviceDetail;
/**
 Unregister any device from any groups in background thread.
 
 @param deviceDetail token and deviceGroupList attributes of NetmeraDeviceDetail instance that you created must not be nil.
 */
+(void) unRegisterInBackgroundWithNetmeraDeviceDetail:(NetmeraDeviceDetail *)deviceDetail;
/**
 Register any device from any groups.
 
 @param deviceDetail token and deviceGroupList attributes of NetmeraDeviceDetail instance that you created must not be nil.
 */
+(void) registerWithNetmeraDeviceDetail:(NetmeraDeviceDetail *)deviceDetail;
/**
 Register any device from any groups in background thread.
 
 @param deviceDetail token and deviceGroupList attributes of NetmeraDeviceDetail instance that you created must not be nil.
 */
+(void) registerInBackgroundWithNetmeraDeviceDetail:(NetmeraDeviceDetail *)deviceDetail;

@end
