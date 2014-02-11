//
//  NSManagedObjectContext+Queryable.h
//  ios-queryable
//
//  Created by Marty on 2012-11-07.
//  Copyright (c) 2012 Marty. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface IQueryable : NSObject<NSFastEnumeration>

-(id)initWithType:(NSString*)type context:(NSManagedObjectContext*)theContext;

-(NSArray*) toArray;

-(IQueryable*)orderBy:(NSString*)fieldName;

-(IQueryable*)orderByDescending:(NSString*)fieldName;

-(IQueryable*)skip:(int)numberToSkip;

-(IQueryable*)take:(int)numberToTake;

-(id)first;

-(id)first:(NSString*)condition, ...;

-(id)firstOrDefault;

-(id)firstOrDefault:(NSString*)condition, ...;

-(id)single;

-(id)single:(NSString*)condition, ...;

-(id)singleOrDefault;

-(id)singleOrDefault:(NSString*)condition, ...;

-(IQueryable*) where:(NSString*)condition, ...;

-(int) count;

-(int) count:(NSString*)condition, ...;

-(bool) any;

-(bool) any:(NSString*)condition, ...;

-(bool) all:(NSString*)condition, ...;

-(double) average:(NSString*)property;

-(double) sum:(NSString*)propertyName;

-(double) min:(NSString*)propertyName;

-(double) max:(NSString*)propertyName;

@end


@interface NSManagedObjectContext (Queryable)

-(IQueryable*)ofType:(NSString*)typeName;

@end

@interface NSManagedObject(Queryable)

+(IQueryable*)queryWithContext: (NSManagedObjectContext*) context;

@end