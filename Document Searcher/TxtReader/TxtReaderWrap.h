//
//  TxtReaderWrap.h
//  Document Searcher
//
//  Created by Justin Chiu on 9/20/17.
//  Copyright © 2017 Justin Chiu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TxtReaderWrap : NSObject

-(id)init;
-(void)dealloc;

-(int)readAndCount_wrapped:(NSString*)filePath
                    second:(NSString*)query;

-(int)rabinKarp_wrapped:(NSString*)filePath
                 second:(NSString*)query;

@end
