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

#include "itkPoint.h"
#include "itkPointSet.h"

int
main()
{
  using PixelType = float;
  constexpr unsigned int Dimension = 3;

  using PointSetType = itk::PointSet<PixelType, Dimension>;
  auto PointSet = PointSetType::New();

  using PointsContainerPointer = PointSetType::PointsContainerPointer;
  PointsContainerPointer points = PointSet->GetPoints();

  // Create points
  using PointType = PointSetType::PointType;
  const PointType p0({ 0.0, 0.0, 0.0 });
  const PointType p1({ 0.1, 0.0, 0.0 });
  const PointType p2({ 0.0, 0.1, 0.0 });

  points->InsertElement(0, p0);
  points->InsertElement(1, p1);
  points->InsertElement(2, p2);

  return EXIT_SUCCESS;
}
