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
 The NetmeraContent object is used to run CRUD operations over the data.
 <p>
 After creating object use add method to fill data and call create method
 to add data into cloud.
 </p>
 \*/
@interface NetmeraContent : NSObject {
    
    
    NSString *objectName;
    
	NSString *path;
    
	NSString *createDate;
    
	NSString *updateDate;
    
    
    NSMutableDictionary *data;
    NSMutableDictionary *mediaData;
    NSMutableDictionary *content;
    NSMutableDictionary *owner;
    NSMutableDictionary *contentType;
    
}

/** Name of the content */
@property(readonly) NSString *objectName;

/** Path to the content */
@property(nonatomic, retain) NSString *path;

/** Create date of the NetmeraContent object */
@property(readonly) NSString *createDate;

/** Update date of the NetmeraContent object */
@property(readonly) NSString *updateDate;


@property(readonly) NSMutableDictionary *data;
@property(readonly) NSMutableDictionary *mediaData;
@property(nonatomic,retain) NSMutableDictionary *content;
@property(nonatomic,retain) NSMutableDictionary *owner;
@property(nonatomic,retain) NSMutableDictionary *contentType;

/**
 Constructor that takes content name as parameter.
 @param objectName Name of the content
 */
- (NetmeraContent *) initWithObjectName:(NSString *) objectName;

/**
 Adds data to the cloud.
 
 @param error if it cannot access server
 */
- (BOOL) create:(NSError**)error;

/**
 Updates data
 
 @param error if it cannot access server
 */
- (BOOL) update:(NSError **)error;

/**
 Deletes data from the cloud.
 @warning Before calling this method path of the data should be setted
 @param error if it cannot access server
 */
- (BOOL) delete:(NSError **)error;

/**
 Adds key,value pairs into the object. If the object contains key, the old
 value is replaced.
 
 @param key key to identify specified value.
 
 @param value value associates with the specified key. This value can be one of these classes instance;
 
 NSString
 
 NSNumber
 
 NSDate
 
 NSData
 
 NSDictionary - members must be one of the above instance
 
 NSArray - members must be one of the above instance
 
 NetmeraGeoLocation
 
 NetmeraMedia
 
 NetmeraUser
 
 @warning Raises an exception if value is not an object that NSDictionary accepts.
 */
- (void) add:(NSString *)key object:(NSObject*) value;

/**
 Set the owner of this content. If it is generic content then do not call setOwner: method.
 
 @param user Owner of the content
 */
- (void) setOwner:(NetmeraUser *)user;

/**
 Adds key,value pairs into the object. If the object contains key, the old
 value is replaced.
 
 @param key key to identify specified value
 @param value BOOL value associates with the specified key
 
 @warning Raises an exception if value is not an object that NSDictionary accepts.
 */
- (void) addBool:(NSString *)key object:(BOOL) value;

/**
 Adds data to the cloud in the background thread. Since it runs on the
 background thread it does not block program.It is recommended over
 create method.
 
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackCreateWithContent:(NetmeraContent *)content error:(NSError *)error. error will be nil on success and set if there was an error. content will be the new creates NetmeraContent object.
 */
- (void)createInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Adds data to the cloud in the background thread and executes the given callback block. Since it runs on the
 background thread it does not block program.It is recommended over
 create method.
 
 @param block The block to execute. The block should have the following argument signature: (NetmeraContent *content, NSError *error)
 */
- (void)createInBackgroundWithBlock:(void(^)(NetmeraContent *content, NSError *error))block;

/**
 Adds data to the cloud in the background thread. Since it runs on the
 background thread it does not block program.It is recommended over
 create method.
 */
- (void)createInBackground;

/**
 Updates data in the background thread. Since it runs on the background
 thread it does not block program.It is recommended over update method.
 
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void)callBackUpdateWithContent:(NetmeraContent *)content error:(NSError *)error. error will be nil on success and set if there was an error. content will be the NetmeraContent with the updated data.
 
 */
- (void)updateInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Updates data in the background thread and executes. Since it runs on the background
 thread it does not block program.It is recommended over update method.
 
 @param block The block to execute. The block should have the following argument signature: (NetmeraContent *content, NSError *error)
 */
- (void)updateInBackgroundWithBlock:(void(^)(NetmeraContent *content, NSError *error))block;

/**
 Deletes data from the cloud in the background thread.Since it runs on the
 background thread it does not block program.It is recommended over
 delete method.
 
 @warning Before calling this method path of the data should be setted
 
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void) callBackDeleteWithError:(NSError *)error. error will be nil on success and set if there was an error.
 */
- (void)deleteInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Deletes data from the cloud in the background thread and executes.Since it runs on the
 background thread it does not block program.It is recommended over
 delete method.
 
 @warning Before calling this method path of the data should be setted
 
 @param block The block to execute. The block should have the following argument signature: (NSError *error)
 */
- (void)deleteInBackgroundWithBlock:(void(^)(NSError *error))block;

/**
 Deletes data from the cloud in the background thread.Since it runs on the
 background thread it does not block program.It is recommended over
 delete method.
 
 @warning Before calling this method path of the data should be setted
 
 */
- (void)deleteInBackground;

/**
 Gets the NSObject with the specified key.
 
 @param key key to get value
 @return Returns the NSObject with the specified key.If the object type is not NSObject or key does not exists then it returns nil.
 
 */
-(NSObject*)get:(NSString*)key;


/**
 Gets the NSString object with the specified key.
 
 @param key key to get value
 @return Returns the NSString with the specified key.If the object type is not NSString or key does not exists then it returns nil.
 
 */
-(NSString*)getString:(NSString*)key;

/**
 Gets the int value with the specified key.
 
 @param key key to get value
 @return Returns the int value with the specified key.If value is not an integer or key does not exists then it returns 0.
 
 */
-(int)getInt:(NSString*)key;


/**
 Gets the long value with the specified key.
 
 @param key key to get value
 @return Returns the long value with the specified key.If value is not a long or key does not exists then it returns 0.
 
 */
-(long)getLong:(NSString*)key;


/**
 Gets the boolean value with the specified key.
 
 @param key key to get value
 @return Returns the boolean value with the specified key.If value is a boolean or key does not exists then it returns false.
 
 */
-(BOOL)getBool:(NSString*)key;


/**
 Gets the double value with the specified key.
 
 @param key key to get value
 @return Returns the double value with the specified key.If value is not a double or key does not exists then it returns 0.0.
 
 */
-(double)getDouble:(NSString*)key;


/**
 Gets the NSDictionary object with the specified key.
 
 @param key key to get value
 @return Returns the NSDictionary object with the specified key.If the object type is not an NSDictionary or key does not exists then it returns nil.
 
 */
-(NSDictionary*)getDictionary:(NSString*)key;

/**
 Gets the NSArray object with the specified key.
 
 @param key key to get value
 @return Returns the NSArray object with the specified key.If the object type is not an NSArray or key does not exists then it returns nil.
 
 */
-(NSArray*)getDictionaryArray:(NSString*)key;


/**
 Gets the NetmeraGeoLocation object with the specified key.
 
 @param key key to get value
 @return Returns the NetmeraGeoLocation object with the specified key.If the object type is not an NetmeraGeoLocation or key does not exists then it returns nil.
 
 */
-(NetmeraGeoLocation*)getNetmeraGeoLocation:(NSString*)key;

/**
 Gets the NetmeraMedia object with the specified key.
 
 @param key key to get value
 @return Returns the NetmeraMedia object with the specified key.If
 the object type is not an NetmeraMedia or key does not
 exists then it returns null.
 */

-(NetmeraMedia*)getNetmeraMedia:(NSString*)key;

/**
 Gets the NetmeraUser object with the specified key.
 
 @param key key to get value
 @return Returns the NetmeraUser object with the specified key.If
 the object type is not an NetmeraUser or key does not
 exists then it returns null.
 */
-(NetmeraUser *) getNetmeraUser:(NSString *)key;

@end
