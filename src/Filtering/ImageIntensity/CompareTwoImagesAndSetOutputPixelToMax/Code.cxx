/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include "itkImage.h"
#include "itkMaximumImageFilter.h"
#include "itkImageRegionIterator.h"

using ImageType = itk::Image<unsigned char, 2>;

static void
CreateImage1(ImageType * image);
static void
CreateImage2(ImageType * image);

int
main()
{
  auto image1 = ImageType::New();
  CreateImage1(image1);

  auto image2 = ImageType::New();
  CreateImage2(image2);

  using MaximumImageFilterType = itk::MaximumImageFilter<ImageType>;

  auto maximumImageFilter = MaximumImageFilterType::New();
  maximumImageFilter->SetInput(0, image1);
  maximumImageFilter->SetInput(1, image2);
  maximumImageFilter->Update();

  return EXIT_SUCCESS;
}

void
CreateImage1(ImageType * image)
{
  ImageType::IndexType start{};

  auto size = ImageType::SizeType::Filled(100);

  ImageType::RegionType region;
  region.SetSize(size);
  region.SetIndex(start);

  image->SetRegions(region);
  image->Allocate();

  itk::ImageRegionIterator<ImageType> imageIterator(image, region);

  while (!imageIterator.IsAtEnd())
  {
    if (imageIterator.GetIndex()[0] < 30)
    {
      imageIterator.Set(255);
    }
    else
    {
      imageIterator.Set(0);
    }

    ++imageIterator;
  }
}

void
CreateImage2(ImageType * image)
{
  ImageType::IndexType start{};

  auto size = ImageType::SizeType::Filled(100);

  ImageType::RegionType region;
  region.SetSize(size);
  region.SetIndex(start);

  image->SetRegions(region);
  image->Allocate();

  itk::ImageRegionIterator<ImageType> imageIterator(image, region);

  while (!imageIterator.IsAtEnd())
  {
    if (imageIterator.GetIndex()[0] > 70)
    {
      imageIterator.Set(255);
    }
    else
    {
      imageIterator.Set(0);
    }

    ++imageIterator;
  }
}
