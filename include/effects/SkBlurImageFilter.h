/*
 * Copyright 2011 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkBlurImageFilter_DEFINED
#define SkBlurImageFilter_DEFINED

#include "SkImageFilter.h"
#include "SkSize.h"

class SK_API SkBlurImageFilter : public SkImageFilter {
public:
    static SkImageFilter* Create(SkScalar sigmaX, SkScalar sigmaY, SkImageFilter* input = NULL,
                                 const CropRect* cropRect = NULL) {
        if (0 == sigmaX && 0 == sigmaY && nullptr == cropRect) {
            return SkSafeRef(input);
        }
        return new SkBlurImageFilter(sigmaX, sigmaY, input, cropRect);
    }

    SkRect computeFastBounds(const SkRect&) const override;

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkBlurImageFilter)

protected:
    void flatten(SkWriteBuffer&) const override;
    SkSpecialImage* onFilterImage(SkSpecialImage* source, const Context&,
                                  SkIPoint* offset) const override;
    SkIRect onFilterNodeBounds(const SkIRect& src, const SkMatrix&, MapDirection) const override;

private:
    SkBlurImageFilter(SkScalar sigmaX,
                      SkScalar sigmaY,
                      SkImageFilter* input,
                      const CropRect* cropRect);

    SkSize   fSigma;
    typedef SkImageFilter INHERITED;
};

#endif
