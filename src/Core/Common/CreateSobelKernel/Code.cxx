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
#include <itkSobelOperator.h>

int
main()
{
  using SobelOperatorType = itk::SobelOperator<float, 2>;
  SobelOperatorType sobelOperator;
  sobelOperator.SetDirection(0); // Create the operator for the X axis derivative
  auto radius = itk::Size<2>::Filled(1);
  sobelOperator.CreateToRadius(radius);

  std::cout << sobelOperator << std::endl;

  for (unsigned int i = 0; i < 9; ++i)
  {
    std::cout << sobelOperator.GetElement(i) << std::endl;
  }
  return EXIT_SUCCESS;
}
