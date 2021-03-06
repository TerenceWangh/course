/*=========================================================================

  Program:   Medical Imaging Toolkit
  Date:      $Date: 2012-1-6 14:00:00 +0800$
  Version:   $Version: 2.3.3 $
  Copyright: MIPG, Institute of Automation, Chinese Academy of Sciences


=========================================================================*/




#ifndef __mitkNodeHeap_h
#define __mitkNodeHeap_h
#include "mitkNode.h"
#include "mitkObject.h"

/// mitkSglNode - a class that define mitkSglNode used by mitkNodeHeap
///////////////////////////////////////////////////////////////////////////
/// mitkSglNode define a single node of a SgnNode link
class MITK_COMMON_API mitkSglNode
{
public:
    ///////////////////////////////////////////////////////////////////////////
    /// Constructor of the class
    ///////////////////////////////////////////////////////////////////////////
    mitkSglNode(){next = NULL;};

    ///////////////////////////////////////////////////////////////////////////
    /// Destructor of the class
    ///////////////////////////////////////////////////////////////////////////
    ~mitkSglNode()
    {
        if (next)
        {
            next = NULL;
        }
    };
    
    mitkNode node;
    mitkSglNode *next;
};

/// mitkNodeHeap - a class that define mitkNodeHeap used by mitkFastMarchingImageFilter
///////////////////////////////////////////////////////////////////////////
/// mitkNodeHeap defines a min-nodeHeap. The top of the heap is always the minimal of 
/// the elements in the heap.

class  MITK_COMMON_API mitkNodeHeap
{
public:
    ///////////////////////////////////////////////////////////////////////////
    /// Constructor of the class
    /////////////////////////////////////////////////////////////////////////// 
    mitkNodeHeap();
    
    ///////////////////////////////////////////////////////////////////////////
    /// Destructor of the class
    /////////////////////////////////////////////////////////////////////////// 
    ~mitkNodeHeap();

    ///////////////////////////////////////////////////////////////////////////
    /// Get the top node of the heap.
    /// \return                   Return the top node of the heap which is also the minimal
    ///                           element of the heap.
    ///////////////////////////////////////////////////////////////////////////
    mitkNode top();

    ///////////////////////////////////////////////////////////////////////////
    /// remove the top node of the heap.
    ///////////////////////////////////////////////////////////////////////////
    void pop();

    ///////////////////////////////////////////////////////////////////////////
    /// Push a node into the heap.
    /// \param node               Represent the node to put into the heap
    ///////////////////////////////////////////////////////////////////////////
    void push(mitkNode node);

    ///////////////////////////////////////////////////////////////////////////
    /// Check if the heap is empty
    /// \return                   Return true if the heap is empty
    ///                           otherwise return false.
    ///////////////////////////////////////////////////////////////////////////
    bool empty();

private:
    mitkSglNode *m_pNodeLink;
    int m_NodeNum;
};

#endif

