#ifndef IVxResourceRel_h__
#define IVxResourceRel_h__

#include "IVxDataSource.h"
#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a related resource; that is, a resource that is related in some way to a parent resource. This
    /// related resource may be linked to its parent resource for some effect.
    /// </summary>
    struct IVxResourceRel {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the related resource.
        /// </summary>
        /// <param name="dataSource">The related resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetResource(IVxDataSource*& dataSource) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the link state of this resource to its parent.
        /// </summary>
        /// <param name="isLinked"><c>true</c> to link this resource to its parent, <c>false</c> to unlink.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetLinkState(bool isLinked) const = 0;

    public:
        /// <summary>
        /// Indicates whether the resource is linked to its parent.
        /// </summary>
        bool isLinked;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isLinked = false;
        }
    };
}
#endif // IVxResourceRel_h__
