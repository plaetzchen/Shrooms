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

#import <Foundation/Foundation.h>
#import "BasePush.h"

/**
 NetmeraPush class is used to send push notifications into ANDROID and IOS
 devices from objective-c code.
 <br>
 <br>
 <code>
 NetmeraPush *push = [[NetmeraPush alloc] initWithMessage:@"Hello, World!" withDeviceGroups:nil isSendToIOS:YES isSendToAndroid:YES];<br>
 [push sendNotificationInBackgroundWithBlock:^(NSError *error, NSMutableDictionary *pushInfoDict) {<br>
 NSLog(@"ios; %@", [pushInfoDict objectForKey:IOS_NAME_KEY]);//IOS_NAME_KEY = IOS<br>
 NSLog(@"android; %@", [pushInfoDict objectForKey:ANDROID_NAME_KEY]);//ANDROID_NAME_KEY = Android
 }];<br>
 </code>
 */
@interface NetmeraPush : BasePush{
    BOOL isSendToIOS;
    BOOL isSendToAndroid;
}
/** YES if you want to send your push notification to IOs devices*/
@property BOOL isSendToIOS;
/** YES if you want to send your push notification to Android devices*/
@property BOOL isSendToAndroid;


/**
 Constractor method that you can easily create instance of NetmeraPush object with push message and its device groups and target mobile operating systems
 
 @param message Body of your push notification
 @param deviceGroups Names of your target group
 @param isSendToIOS BOOL parameter if you want to send your push notification to IOs devices
 @param isSendToAndroid BOOL parameter if you want to send your push notification to Android devices
 */
- (id) initWithMessage:(NSString *)message withDeviceGroups:(NSArray *)deviceGroups isSendToIOS:(BOOL)isSendToIOS isSendToAndroid:(BOOL)isSendToAndroid;

/**
 Sends notification to IOs and/or Android devices.
 
 @param error if it cannot access server
 @return NSMutableDictionary include max. two NetmeraPushInfo object with keys "IOS" and "Android"
 */
-(NSMutableDictionary *)sendNotificationWithError:(NSError **)error;

/**
 Sends notification to IOs and/or Android devices  in the background thread.
 */
-(void)sendNotificationInBackground;

/**
 Sends notification to IOs and/or Android devices  in the background thread.
 
 @param block The block to execute. The block should have the following argument signature: (NSError *error, NetmeraPushInfo *pushInfo)
 */
-(void)sendNotificationInBackgroundWithBlock:(void(^)(NSError *error, NSMutableDictionary *pushInfoDict))block;

/**
 Sends notification to IOs and/or Android devices  in the background thread.
 
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackSendNotificationWithError:(NSError *)error pushInfoList:(NSMutableDictionary *)infoList
 */
-(void)sendNotificationInBackgroundWithTarget:(id)target selector:(SEL)selector;


@end
