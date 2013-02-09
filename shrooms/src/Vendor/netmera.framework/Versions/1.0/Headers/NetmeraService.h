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
 NetmeraService is used to get NetmeraContent object by its search
 and get methods. Many query options defined to help finding exact object.
 
 */
@interface NetmeraService : NSObject{
    enum SortOrder {
		ascending, descending
	};
    
    
}
extern NSString * const NEARBY;
/** Name of the content */
@property(nonatomic,retain)NSString *objectName;

/** List to add queries for the search */
@property(nonatomic,retain)NSMutableArray *queries;

/** List to add queries for the search */
@property(nonatomic,retain) NSMutableDictionary *conditionalMap;

/** Text to search */
@property(nonatomic,retain)NSString *searchText;

/**the search type*/
@property(nonatomic,retain)NSString *searchType;

/**the field that holds location info*/
@property(nonatomic,retain)NSString *locationSearchField;

/** Maximum number of the content to return */
@property(nonatomic, setter = setMax:)int max;

/** Number of the pages */
@property(nonatomic, setter = setPage:)int page;

/** Path of the content */
@property(nonatomic,retain)NSString *path;

@property(nonatomic,retain)NSString *sortBy;

@property(nonatomic)enum SortOrder sortOrder;

/**
 Default constructor for the NetmeraService that sets objectName and other default parameters.
 
 @warning Default value for the max = 10 and page = 0. It returns 10 result in each
 page. It skips page * max in each iteration.
 
 @param objectName Name of the content
 */
-(id)initWithName:(NSString*)objectName;


/**
 Gets the total number of results that matches the query.
 
 @return Returns the total number of results
 @param error if it cannot access server.
 */
-(long)count:(NSError**)error;

/**
 Gets the total number of results that match the query in the background
 thread.Since it runs on the background thread it does not block
 program.It is recommended over count method.
 
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void)callBackCountWithCount:(NSNumber*)count error:(NSError *)error. error will be nil on success and set if there was an error. count will tell count of contents
 */
-(void)countInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Gets the total number of results that match the query in the background
 thread and executes.Since it runs on the background thread it does not block
 program.It is recommended over count method.
 
 @param block The block to execute. The block should have the following argument signature: (NSNumber *count, NSError *error)
 */
-(void)countInBackgroundWithBlock:(void(^)(NSNumber *count, NSError *error))block;

/**
 Adds the searchText into the query.
 
 @param searchText Text to search
 */
-(void)addSearchText:(NSString*)searchText;

/**
 This is used to get the contents of the logged user.
 
 @param user current user
 */
-(void)whereOwnerEqual:(NetmeraUser*)user;

/**
 Adds an options to the query where value that matches with the query is
 equal to the given value.
 
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereEqualWithKey:(NSString*)key  andValue:(id)value;

/**
 Adds an options to the query where value that matches with the query is
 greater than the given value.
 
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereGreatherThanWithKey:(NSString*)key andValue:(id)value;

/**
 Adds an options to the query where value that matches with the query is
 less than the given value.
 
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereLessThanWithKey:(NSString*)key andValue:(id)value;

/**
 Adds an options to the query where value that matches with the query is
 not equal to the given value.
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereNotEqualWithKey:(NSString*)key andValue:(id)value;

/**
 Adds an options to the query where value that matches with the query is
 greater than or equal to the given value.
 
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereGreatherThanOrEqualWithKey:(NSString*)key andValue:(id)value;


/**
 Adds an options to the query where value that matches with the query is
 less than or equal to the given value.
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereLessThanOrEqualWithKey:(NSString*)key andValue:(id)value;

/**
 Adds an options to the query where the given key is exists or not. If
 value is true then it checks whether key exists, if value is false then
 it checks whether key not exists.
 
 @param key key to identify specified value
 @param value BOOL value to check whether key exists or not
 */
-(void)whereExistsWithKey:(NSString*)key andValue:(BOOL)value;

/**
 Adds an options to the query where value that returns from the query
 matches with the given regex.
 
 @param key key to identify specified value
 @param regex value associates with the specified key
 */
-(void)whereMatchesWithKey:(NSString*)key andRegex:(NSString *)regex;

/**
 Adds an options to the query where value that matches with the query
 starts with the given prefix.
 @param key key to identify specified value
 @param prefix value associates with the specified key
 */
-(void)whereStartsWithWithKey:(NSString*)key andPrefix:(id)prefix;

/**
 Adds an options to the query where value that matches with the query ends
 with the given suffix.
 @param key key to identify specified value
 @param suffix value associates with the specified key
 */
-(void)whereEndsWithWithKey:(NSString*)key andSuffix:(id)suffix;

/**
 Adds an options to the query where value that matches with the query
 contains any of the values in the given collection.
 @param key key to identify specified value
 @param values values associates with the specified key
 */
-(void)whereContainedInWithKey:(NSString*)key andValues:(NSArray*)values;

/**
 Adds an options to the query where value that matches with the query
 contains all of the values in the given collection.
 @param key key to identify specified value
 @param values values associates with the specified key
 */
-(void)whereAllContaintedInWithKey:(NSString*)key andValues:(NSArray*)values;

/**
 Searches the content by taking given location as a base and retrieves the
 contents that located given distance far away.
 
 @param startLocation base location to search near it.
 @param distance is used to create circle by taking the startLocation as a center.
 @param locationSearchField name of the field that holds location data.
 @param error if it cannot access server
 @return the list of NetmeraContent object.
 
 */
-(NSArray*)circleSearchWithStartLocation:(NetmeraGeoLocation*)startLocation andDistance:(double)distance andlocationSearchField:(NSString*)locationSearchField withError:(NSError**)error;

/**
 Searches the content by taking given location as a base and retrieves the
 contents that located given distance far away in the background
 thread.Since it runs on the background thread it does not block
 program.It is recommended over circleSearch method.
 
 @param startLocation base location to search near it.
 @param distance is used to create circle by taking the startLocation as a center.
 @param locationSearchField name of the field that holds location data.
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: callBackCircleSearchWithContentArray:(NSArray*)netmeraContentArray error:(NSError *)error. error will be nil on success and set if there was an error. netmeraContentArray(NSArray with NetmeraContent) is the result of search query.
 */
-(void)circleSearchInBackgroundWithTarget:(id)target selector:(SEL)selector startLocation:(NetmeraGeoLocation*)startLocation distance:(double)distance locationSearchField:(NSString*)locationSearchField;


/**
 Creates box using the given two location (latitude,longitude) data and
 searches inside that box.
 
 @param firstPoint NetmeraGeoLocation object
 @param secondPoint NetmeraGeoLocation object
 @param locationSearchField name of the field that holds location data.
 @param error if it cannot access server
 @return the list of NetmeraContent object.
 */
-(NSArray*)boxSearchWithFirstLocation:(NetmeraGeoLocation*)firstPoint andSecondPoint:(NetmeraGeoLocation*)secondPoint andlocationSearchField:(NSString*)locationSearchField withError:(NSError**)error;

/**
 Creates box using the given two location (latitude,longitude) data and
 searches inside that box in the background thread.Since it runs on the
 background thread it does not block program.It is recommended over
 boxSearch method.
 
 @param firstPoint NetmeraGeoLocation object
 @param secondPoint NetmeraGeoLocation object
 @param locationSearchField name of the field that holds location data.
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void) callBackBoxSearchWithContentArray:(NSArray*)netmeraContentArray error:(NSError *)error. error will be nil on success and set if there was an error. netmeraContentArray(NSArray with NetmeraContent) is the result of search query.
 */
-(void)boxSearchInBackgroundWithTarget:(id)target selector:(SEL)selector firstLocation:(NetmeraGeoLocation*)firstPoint secondPoint:(NetmeraGeoLocation*)secondPoint locationSearchField:(NSString*)locationSearchField;

/**
 Gets the list of NetmeraContent from the network.
 @param error if it cannot access server
 */
-(NSArray*)search:(NSError**)error;

/**
 Retrieves the list of NetmeraContent objects that matches with
 the query in the background thread.Since it runs on the background thread
 it does not block program.It is recommended over search method.
 
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void) callBackSearchWithContentArray:(NSArray*)netmeraContentArray error:(NSError *)error. error will be nil on success and set if there was an error. netmeraContentArray(NSArray with NetmeraContent) is the result of search query.
 */
-(void)searchInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Retrieves the list of NetmeraContent objects that matches with
 the query in the background thread and executes.Since it runs on the background thread
 it does not block program.It is recommended over search method.
 
 @param block The block to execute. The block should have the following argument signature: (NSArray *netmeraContentArray, NSError *error)
 */
-(void)searchInBackgroundWithBlock:(void(^)(NSArray *netmeraContentArray, NSError *error))block;

/**
 Gets the single NetmeraContent object that matches the query.
 
 @param error if it cannot access server
 */
-(NetmeraContent*)get:(NSError**)error;

/**
 Gets the single NetmeraContent object that matches the query in
 the background thread.Since it runs on the background thread it does not
 block program.It is recommended over get method.
 
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void)callBackGetWithContent:(NetmeraContent *)content error:(NSError *)error. error will be nil on success and set if there was an error. content will ne the NetmeraContent object.
 */
-(void)getInBackgroundWithtTarget:(id)target selector:(SEL)selector;

/**
 Gets the single NetmeraContent object that matches the query in
 the background thread and executes.Since it runs on the background thread it does not
 block program.It is recommended over get method.
 
 @param block The block to execute. The block should have the following argument signature: (NetmeraContent *content, NSError *error)
 */
-(void)getInBackgroundWithBlock:(void(^)(NetmeraContent *content, NSError *error))block;

/**
 Gets the queries list of queries and merges them as single query.
 */
-(NSString*)getCustomCondition;

/**
 Retrieves the list of NetmeraUser objects that matches with the query.
 
 @param error if it cannot access server
 @return List of the NetmeraUser array
 */
-(NSArray *)searchUser:(NSError **)error;

@end