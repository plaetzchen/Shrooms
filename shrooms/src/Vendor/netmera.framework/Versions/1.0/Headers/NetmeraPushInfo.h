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
 NetmeraPushInfo class is used to inform you about your push notification that you sent
 */
@interface NetmeraPushInfo : NSObject{
    NSString *path;
    NSString *status;
    NSString *errorMessage;
    NSNumber *successfullDeviceCount;
    NSNumber *failedDeviceCount;
    NSString *pushMessage;
    NSDate *sendDate;
    NSDate *finishDate;
}

/** unique path that you can search info content of your push notification*/
@property(nonatomic,retain) NSString *path;
/** status of your push notification message*/
@property(nonatomic,retain) NSString *status;
/** error message if push notification gets an error*/
@property(nonatomic,retain) NSString *errorMessage;
/** gives you information about device count that successfully receive your notification*/
@property(nonatomic,retain) NSNumber *successfullDeviceCount;
/** gives you information about device count of failed to receive your push*/
@property(nonatomic,retain) NSNumber *failedDeviceCount;
/** body text of your push notification*/
@property(nonatomic,retain) NSString *pushMessage;
/** send date of your push notification*/
@property(nonatomic,retain) NSDate *sendDate;
/** finish date of sending your push notification all of your target devices */
@property(nonatomic,retain) NSDate *finishDate;

@end
