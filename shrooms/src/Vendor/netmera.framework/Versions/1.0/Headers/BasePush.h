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

@interface BasePush : NSObject{
    NSString *message;
    NSArray *deviceGroups;
}
/** IOS_NAME_KEY = IOS */
extern NSString * const IOS_NAME_KEY;
/** ANDROID_NAME_KEY = Android */
extern NSString * const ANDROID_NAME_KEY;

/** body text of your push notification */
@property(nonatomic,retain)NSString *message;
/** target group names of your push notification */
@property(nonatomic,retain)NSArray *deviceGroups;

@end
