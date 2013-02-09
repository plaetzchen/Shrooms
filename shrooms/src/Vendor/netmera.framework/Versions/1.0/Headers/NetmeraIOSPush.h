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

#import "BasePush.h"
#import "NetmeraPush.h"
#import "NetmeraPushInfo.h"


/**
 NetmeraIOSPush class is used to send push notifications into IOs devices from objective-c code.
 <br>
 <br>
 <code>
 NetmeraIOSPush *push = [[NetmeraIOSPush alloc] initWithMessage:@"Hello, IOS Devices!" withDeviceGroups:nil];<br>
 [push sendNotificationInBackgroundWithBlock:^(NSError *error, NetmeraPushInfo *pushInfo) {<br>
 NSLog(@"pushInfo.pushMessage; %@", pushInfo.pushMessage);<br>
 NSLog(@"pushInfo.status; %@", pushInfo.status);<br>
 }];<br>
 </code>
 */
@interface NetmeraIOSPush : BasePush

/**
 Constractor method that you can easily create instance of NetmeraIOSPush object with push message and its device groups
 
 @param message Body of your push notification
 @param deviceGroups Names of your target group
 
 */
- (id) initWithMessage:(NSString *)message withDeviceGroups:(NSArray *)deviceGroups;

/**
 Sends notification to IOs devices.
 
 @param error if it cannot access server
 @return NetmeraPushInfo object that includes information about your push message
 */
-(NetmeraPushInfo *)sendNotificationWithError:(NSError **)error;

/**
 Sends notification to IOs devices  in the background thread.
 */
-(void)sendNotificationInBackground;

/**
 Sends notification to IOs devices  in the background thread.
 
 @param block The block to execute. The block should have the following argument signature: (NSError *error, NetmeraPushInfo *pushInfo)
 */
-(void)sendNotificationInBackgroundWithBlock:(void(^)(NSError *error, NetmeraPushInfo *pushInfo))block;

/**
 Sends notification to IOs devices  in the background thread.
 
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackSendNotificationWithError:(NSError *)error pushInfo:(NetmeraPushInfo *)info
 */
-(void)sendNotificationInBackgroundWithTarget:(id)target selector:(SEL)selector;

@end
