// Copyright (c) 2014 Yohsuke Yukishita
// This software is released under the MIT License: http://opensource.org/licenses/mit-license.php

#import "TGLShaderWrapper.h"
#import "MCVBufferFreight.h"

@interface MCVConnectedComponent : NSObject
@property (nonatomic, readwrite) CGRect rect;
@property (nonatomic, readwrite) float density;
@property (nonatomic, readonly) CGPoint centroid;
@end

struct MCVConnectedComponentConfig {
    struct {
        int min_w;
        int min_h;
        int max_w;
        int max_h;
    } filter;
};

#define MCVConnectedComponentConfigDefault ((struct MCVConnectedComponentConfig){ .filter = {2, 2, 100, 100} })

@interface MCVConnectedComponentLabeling : TGLShaderWrapper

+ (MCVConnectedComponentLabeling *)createWithSize:(CGSize)size;

- (BOOL)configure:(struct MCVConnectedComponentConfig)config;

- (BOOL)debugProcess:(MCVBufferFreight *)src to:(MCVBufferFreight *)dst;

// array of GLConnectedComponent
- (NSArray *)process:(MCVBufferFreight *)src;

@end

