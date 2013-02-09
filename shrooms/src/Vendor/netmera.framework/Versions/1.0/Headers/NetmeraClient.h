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
 NetmeraClient class contains the configuration methods.
 */
@interface NetmeraClient : NSObject{
    /**
     Types of the Cache to use while searching.
     */
    enum CacheType{
		/**
         Queries does not add and retrieve results to cache.
         */
		DEFAULT_NO_CACHE,
        
		/**
         Queries retrieve results from the cache.
         */
		FROM_CACHE,
        
		/**
		 Queries retrieve results from the network and add results into the
		 cache.
		 */
		FROM_NETWORK,
        
		/**
		 Queries first tries to get results from cache, if it cannot find then
		 tries to get from network.
		 */
		FIRST_CACHE_THEN_NETWORK,
        
		/**
		 Queries first tries to get results from network, if it cannot find
		 then tries to get from cache.
		 */
		FIRST_NETWORK_THEN_CACHE
	};
}

/**
 Types of the Cache to use while searching.
 @warning enum CacheType options.
 
 DEFAULT_NO_CACHE, Queries does not add and retrieve results to cache.
 
 FROM_CACHE, Queries retrieve results from the cache.

 FROM_NETWORK, Queries retrieve results from the network and add results into the
 cache.
 
 FIRST_CACHE_THEN_NETWORK, Queries first tries to get results from cache, if it cannot find then
 tries to get from network.
 
 FIRST_NETWORK_THEN_CACHE, Queries first tries to get results from network, if it cannot find
 then tries to get from cache.
 
 */
@property(nonatomic)enum CacheType cacheType;

/**
 Set cache method of netmera
 @param cacheType Type of the cache method
 @warning enum CacheType options.
 
 DEFAULT_NO_CACHE, Queries does not add and retrieve results to cache.
 
 FROM_CACHE, Queries retrieve results from the cache.
 
 FROM_NETWORK, Queries retrieve results from the network and add results into the
 cache.
 
 FIRST_CACHE_THEN_NETWORK, Queries first tries to get results from cache, if it cannot find then
 tries to get from network.
 
 FIRST_NETWORK_THEN_CACHE, Queries first tries to get results from network, if it cannot find
 then tries to get from cache.

 */
+(void)setCacheType:(enum CacheType) cacheType;

/**
 Deletes everything from the cache
 */
+(void) deleteCacheResults;

/**
 Authenticates user and application. It is recommended to call this method
 at the beginning of the program.
 @param apiKey key that given from Netmera account of your project
 */
+ (void)initWithApiKey:(NSString *)apiKey;

- (NSData *) sendHttpGETWithUrlString:(NSString *)urlString error:(NSError **)error __attribute__((deprecated));

- (NSData *) sendHttpPostWithUrlString:(NSString *)urlString parametersMap:(NSDictionary *)dictionary error:(NSError **)error __attribute__((deprecated));

- (NSData *) sendWithUrl:(NSString *)urlString parametersMap:(NSDictionary *)dictionary withHTTPMethod:(NSString *)httpMethod error:(NSError **)error isCacheEnable:(BOOL)isCacheEnable;

- (NSData *) sendForOpenSocialWithUrl:(NSString *)urlString rest:(NSString *)rest parametersMap:(NSDictionary *)dictionary withHTTPMethod:(NSString *)httpMethod error:(NSError **)error;

- (NSData *) sendWithHttpBoddy:(NSData *)data url:(NSString *)urlString parametersMap:(NSDictionary *)dictionary withHTTPMethod:(NSString *)httpMethod error:(NSError **)error;

- (NSData *) sendAPIKEYWithUrl:(NSString *)urlString parametersMap:(NSDictionary *)dictionary withHTTPMethod:(NSString *)httpMethod error:(NSError **)error isCacheEnable:(BOOL)isCacheEnable;
@end