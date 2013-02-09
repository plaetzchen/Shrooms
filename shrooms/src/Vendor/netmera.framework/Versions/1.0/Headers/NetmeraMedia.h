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
 NetmeraMedia object is used to create media content.
 <p>
 Its constructor is used to create different types of media content.
 </p>
 */
@interface NetmeraMedia : NSObject{
    
    enum PhotoSize {
		DEFAULT,
        
		THUMBNAIL,
		
		SMALL,
        
		MEDIUM,
        
		LARGE
	};
    
    
    NSData *data;
    
    
	NSString *url;
    
	NSString *key;
    
}

@property (nonatomic, retain) NSString *key;
/** NSData that holds image data */
@property (nonatomic, retain, getter = getData) NSData *data;
/** Path of the media */
@property (nonatomic, retain) NSString *url;

/**
 Constructor that takes byte array as a parameter and creates NetmeraMedia object.
 
 @param data The image's data
 */
- (NetmeraMedia *) initWithData:(NSData  *) data;


/**
 
 Returns the URL of file with the given size.
 
 @param size PhotoSize object
 @return NSURL of the photo with the given size.
 */
- (NSURL *)getUrlWithPhotoSize:(enum PhotoSize)size;

/**
 
 Returns the data of file with the default size.
 
 @return NSData of the photo.
 */
- (NSData *)getData;

/**
 
 Returns the data of file with the given size.
 
 @param size PhotoSize object
 @return NSData of the photo with the given size.
 */
- (NSData *)getDataWithPhotoSize:(enum PhotoSize)size;

@end
