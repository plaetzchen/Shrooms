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
#import "Netmera.h"

/**
 NetmeraGeoLocation is used to create location with the given latitude and
 longitude values. It is used to set location into the content and then use it
 on the search queries.
 */
@interface NetmeraGeoLocation : NSObject

@property(nonatomic,setter = setLatitude:)double latitude;

@property(nonatomic,setter = setLongitude:)double longitude;

/**
 Creates location with the given latitude and longitude.
 
 @param latitude must be between the range of (-90,90)
 @param longitude must be between the range of (-180,180)
 */
-(id)initWithLatitude:(double)latitude andLongitude:(double)longitude;

/**
 Set latitude into the location. Latitude must be between the range of (-90.0, 90.0).
 
 @param latitude Location's latitude
 */
-(void)setLatitude:(double)latitude;

/**
 Set longitude into the location. Longitude must be between the range of (-180.0, 180.0).
 @param longitude Location's longitude
 */
-(void)setLongitude:(double)longitude;

@end