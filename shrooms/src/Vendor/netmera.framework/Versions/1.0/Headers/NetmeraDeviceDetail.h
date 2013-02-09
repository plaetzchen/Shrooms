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

/**
 NetmeraDeviceDetail class is used to inform you about any device token that you register before
 */
@interface NetmeraDeviceDetail : NSObject{
    NSString *token;
    NSString *channel;
    NSDate *registerDate;
    NSMutableArray *deviceGroupList;
}

/** unique id that express device with your application created by mobile operating system*/
@property(nonatomic,retain)NSString *token;
/** identify token if it is IOS or Android device*/
@property(nonatomic,retain)NSString *channel;
/** registration date of token*/
@property(nonatomic,retain)NSDate *registerDate;
/** groups name list of token*/
@property(nonatomic,retain)NSMutableArray *deviceGroupList;

/**
 Gets device detail of token
 
 @param token unique id that express device with your application created by mobile operating system
 @param error if it cannot access server
 @return NetmeraDeviceDetail that inform you about given device token
 */
+(NetmeraDeviceDetail *)getDeviceDetailWithToken:(NSString *)token withError:(NSError **)error;

@end
