//
//  NSDictionary+JSONSupport.h
//  VMCategories
//
//  Created by Jimmy on 14/03/13.
//  Copyright (c) 2013 VarshylMobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSDictionaryHelper.h"

/**
 * Adds support for common tasks when dealing with JSON data.
 *
 * Fetch methods assume that the dictionary contains string values decoded
 * from JSON or NSNull. They will attempt to decode the string values into the
 * specified form, and will return error if the key didn't exist, was NSNull,
 * or the value could not be converted (invalid data).
 */
@interface NSDictionary (JSONSupport)

#pragma mark JSONxxxForKey

/** Get a boolean value in a JSON dictionary.
 *
 * @param key The key to fetch a value for.
 * @param defaultValue The value to return on error.
 * @return The decoded value, or defaultValue on error.
 */
- (BOOL) JSONBoolForKey:(NSString*) key defaultValue:(BOOL) defaultValue;

/** Get an integer value in a JSON dictionary.
 *
 * @param key The key to fetch a value for.
 * @param defaultValue The value to return on error.
 * @return The decoded value, or defaultValue on error.
 */
- (int64_t) JSONIntegerForKey:(NSString*) key defaultValue:(int64_t) defaultValue;

/** Get an unsigned integer value in a JSON dictionary.
 *
 * @param key The key to fetch a value for.
 * @param defaultValue The value to return on error.
 * @return The decoded value, or defaultValue on error.
 */
- (uint64_t) JSONUIntegerForKey:(NSString*) key defaultValue:(uint64_t) defaultValue;

/** Get a floating point value in a JSON dictionary.
 *
 * @param key The key to fetch a value for.
 * @param defaultValue The value to return on error.
 * @return The decoded value, or defaultValue on error.
 */
- (double) JSONFloatForKey:(NSString*) key defaultValue:(double) defaultValue;

/** Get a number value in a JSON dictionary.
 *
 * @param key The key to fetch a value for.
 * @param defaultValue The value to return on error.
 * @return The decoded value, or defaultValue on error.
 */
- (NSNumber*) JSONNumberForKey:(NSString*) key defaultValue:(NSNumber*) defaultValue;

/** Get an integer to be interpreted as the number of seconds since Jan 1, 1970,
 * and convert to a date.
 *
 * @param key The key to fetch a value for.
 * @param defaultValue The value to return on error.
 * @return The decoded value, or defaultValue on error.
 */
- (NSDate*) JSONDateInSecondsForKey:(NSString*) key defaultValue:(NSDate*) defaultValue;

/** Get a string value in a JSON dictionary.
 *
 * @param key The key to fetch a value for.
 * @param defaultValue The value to return on error.
 * @return The decoded value, or defaultValue on error.
 */
- (NSString*) JSONStringForKey:(NSString*) key defaultValue:(NSString*) defaultValue;

/** Get a dictionary value in a JSON dictionary.
 *
 * @param key The key to fetch a value for.
 * @param defaultValue The value to return on error.
 * @return The decoded value, or defaultValue on error.
 */
- (NSDictionary*) JSONDictionaryForKey:(NSString*) key defaultValue:(NSDictionary*) defaultValue;

/** Get an array value in a JSON dictionary.
 *
 * @param key The key to fetch a value for.
 * @param defaultValue The value to return on error.
 * @return The decoded value, or defaultValue on error.
 */
- (NSArray*) JSONArrayForKey:(NSString*) key defaultValue:(NSArray*) defaultValue;



#pragma mark readJSONxxx

/** Get a boolean value in a JSON dictionary.
 *
 * @param value Storage space for the resulting value.
 * @param key The key to fetch a value for.
 * @return YES if the value was successfully decoded.
 */
- (BOOL) readJSONBool:(BOOL*) value forKey:(NSString*) key;

/** Get an integer value in a JSON dictionary.
 *
 * @param value Storage space for the resulting value.
 * @param key The key to fetch a value for.
 * @return YES if the value was successfully decoded.
 */
- (BOOL) readJSONInteger:(int64_t*) value forKey:(NSString*) key;

/** Get an unsigned integer value in a JSON dictionary.
 *
 * @param value Storage space for the resulting value.
 * @param key The key to fetch a value for.
 * @return YES if the value was successfully decoded.
 */
- (BOOL) readJSONUInteger:(uint64_t*) value forKey:(NSString*) key;

/** Get a floating point value in a JSON dictionary.
 *
 * @param value Storage space for the resulting value.
 * @param key The key to fetch a value for.
 * @return YES if the value was successfully decoded.
 */
- (BOOL) readJSONFloat:(double*) value forKey:(NSString*) key;

/** Get a number value in a JSON dictionary.
 *
 * @param value Storage space for the resulting value.
 *              If successful, it will be filled with an autoreleased object.
 * @param key The key to fetch a value for.
 * @return YES if the value was successfully decoded.
 */
- (BOOL) readJSONNumber:(NSNumber**) value forKey:(NSString*) key;

/** Get an integer from a JSON dictionary, to be interpreted as the number of
 * seconds since Jan 1, 1970, and convert to a date.
 *
 * @param value Storage space for the resulting value.
 *              If successful, it will be filled with an autoreleased object.
 * @param key The key to fetch a value for.
 * @return YES if the value was successfully decoded.
 */
- (BOOL) readJSONDateInSeconds:(NSDate**) value forKey:(NSString*) key;

/** Get a string value in a JSON dictionary.
 *
 * @param value Storage space for the resulting value.
 *              If successful, it will be filled with an autoreleased object.
 * @param key The key to fetch a value for.
 * @return YES if the value was successfully decoded.
 */
- (BOOL) readJSONString:(NSString**) value forKey:(NSString*) key;

/** Get a dictionary value in a JSON dictionary.
 *
 * @param value Storage space for the resulting value.
 *              If successful, it will be filled with an autoreleased object.
 * @param key The key to fetch a value for.
 * @return YES if the value was successfully decoded.
 */
- (BOOL) readJSONDictionary:(NSDictionary**) value forKey:(NSString*) key;

/** Get an array value in a JSON dictionary.
 *
 * @param value Storage space for the resulting value.
 *              If successful, it will be filled with an autoreleased object.
 * @param key The key to fetch a value for.
 * @return YES if the value was successfully decoded.
 */
- (BOOL) readJSONArray:(NSArray**) value forKey:(NSString*) key;

@end


@interface NSMutableDictionary (JSONSupport)

#pragma mark setJSONxxx

/** Set a boolean value in a JSON dictionary, converting to string.
 *
 * @param value The value to store.
 * @param key The key to store under.
 */
- (void) setJSONBool:(BOOL) value forKey:(NSString*) key;

/** Set an integer value in a JSON dictionary, converting to string.
 *
 * @param value The value to store.
 * @param key The key to store under.
 */
- (void) setJSONInteger:(int64_t) value forKey:(NSString*) key;

/** Set an unsigned integer value in a JSON dictionary, converting to string.
 *
 * @param value The value to store.
 * @param key The key to store under.
 */
- (void) setJSONUInteger:(uint64_t) value forKey:(NSString*) key;

/** Set a floating point value in a JSON dictionary, converting to string.
 *
 * @param value The value to store.
 * @param key The key to store under.
 */
- (void) setJSONFloat:(double) value forKey:(NSString*) key;

/** Set a number value in a JSON dictionary, converting to string.
 *
 * @param value The value to store (stores NSNull if this is nil).
 * @param key The key to store under.
 */
- (void) setJSONNumber:(NSNumber*) value forKey:(NSString*) key;

/** Set a date value in a JSON dictionary, converting to an integer representing
 * the number of seconds since Jan 1, 1970.
 *
 * @param value The value to store (stores NSNull if this is nil).
 * @param key The key to store under.
 */
- (void) setJSONDateInSeconds:(NSDate*) value forKey:(NSString*) key;

/** Set a string value in a JSON dictionary.
 *
 * @param value The value to store (stores NSNull if this is nil).
 * @param key The key to store under.
 */
- (void) setJSONString:(NSString*) value forKey:(NSString*) key;

/** Set a dictionary value in a JSON dictionary.
 *
 * @param value The value to store (stores NSNull if this is nil).
 * @param key The key to store under.
 */
- (void) setJSONDictionary:(NSDictionary*) value forKey:(NSString*) key;

/** Set an array value in a JSON dictionary.
 *
 * @param value The value to store (stores NSNull if this is nil).
 * @param key The key to store under.
 */
- (void) setJSONArray:(NSArray*) value forKey:(NSString*) key;

- (id)objectOrNilForKey:(id)aKey;

@end
