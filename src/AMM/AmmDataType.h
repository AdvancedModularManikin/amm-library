
#pragma once

#include <string>

#include <fastrtps/Domain.h>
#include <fastrtps/participant/Participant.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/subscriber/SampleInfo.h>

#include "AMM/DDS_Listeners.h"

namespace AMM {


/// AMM template class for handling AMM-DDS topics.
///
/// @attention This specialization of AmmDataType should be used if a static or non-static method from
/// a class instance is going to be used as the call back for subscribed events. An instance of AmmDataType
/// doesn't have to be nested in that very object receiving subscribed events, however AmmDataType needs to
/// be aware of that object's type to correctly translate function pointers.
///
/// The following template variables are examples of how to use this tempate.
/// T = AMM::AssessmentPubSubType
/// L = DDS_Listeners::AssessmentListener
/// A = AMM::Assessment
/// U = Parent class (The class that contains a method intended to recieved subscribed event.)
    template<class T, class L, class A, class U = void>
    class AmmDataType {
    private:

        /// Pointer to the DDS Participant managed by the DDS Manager.
        eprosima::fastrtps::Participant *m_participant;

        /// Pointer to the Publisher Listener managed by the DDS Manager.
        DDS_Listeners::PubListener *m_pubListener;

        /// Pointer to the Amm PubSub Type defined in this template.
        ///
        /// @note Is managed internally by this template class.
        /// @note e.g. T = AMM::AssessmentPubSubType
        T *m_type;

        /// Pointer to the Subscriber Listener defined in this template.
        ///
        /// @note Is managed internally by this template class.
        /// @note e.g. L = DDS_Listeners::AssessmentListener.
        L *m_listener;

        /// Publisher of the Amm Data Type defined by this template.
        eprosima::fastrtps::Publisher *m_publisher;

        /// Subscriber of the Amm Data Type defined by this template.
        eprosima::fastrtps::Subscriber *m_subscriber;

        /// Is the publisher of this type initialized?
        ///
        /// @note Prevents access to a null publisher pointer.
        bool m_isPubInit = false;

        /// Is the subscriber of this type initialized?
        ///
        /// @note Prevent access to a null subscriber pointer.
        bool m_isSubInit = false;

        /// Name of this AMM Data Type that is to be registered on the DDS network.
        std::string m_topicName;

        /// Pointer to the function that is called when a subscribed event occurs.
        ///
        /// @note Takes data from an object type that is defined by this template.
        /// @note e.g A = AMM::Assessment.
        void (U::*m_onEvent)(A &, eprosima::fastrtps::SampleInfo_t *);

        /// Pointer to the parent object that is receiving subscribed events.
        ///
        /// @note This is an outside reference. It is not managed by this class.
        U *m_parentClass;

    private:

        /// Attempt to clean up all objects created or initialized by this class.
        /// @note Will throw silent errors if any occur during cleanup, but will continue to remove all used objects.
        void ForceDelete();

    public:

        /// Constructor for initializing an Amm Data Type.
        ///
        /// @param a Name of this type that willb e registered on the DDS network.
        /// @param b DDS Participant that is managed from the DDS Manager.
        /// @param c DDS Publisher Listener that is managed from the DDS Manager.
        AmmDataType(const std::string topicName, eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl);

        /// Constructor for initializing an Amm Data Type.
        ///
        /// This is primarily used for error handling since the internal logic of this constructor
        /// can throw errors and end the routine prematurely.
        /// @param a Error code output. Is 0 if routine is successful.
        /// @param b Name of this type that willb e registered on the DDS network.
        /// @param c DDS Participant that is managed from the DDS Manager.
        /// @param d DDS Publisher Listener that is managed from the DDS Manager.
        AmmDataType(
                int &err, const std::string topicName,
                eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl
        );

        /// Constructor for initializing an Amm Data Type.
        ///
        /// This is primarily used for error handling since the internal logic of this constructor
        /// can throw errors and end the routine prematurely.
        /// @param a Error code output. Is 0 if routine is successful.
        /// @param b Error message output describing the error if any.
        /// @param c Name of this type that willb e registered on the DDS network.
        /// @param d DDS Participant that is managed from the DDS Manager.
        /// @param e DDS Publisher Listener that is managed from the DDS Manager.
        AmmDataType(
                int &err, std::string &errmsg, const std::string topicName,
                eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl
        );

        /// Default deconstructor.
        ///
        /// Calls Force Delete when used.
        /// @note It is safe to call the deconstructor on this as opposed to calling Shutdown since Force Delete
        /// will ensure that a cleanup routine is at least attempted if not already, however it is not recommened.
        ~AmmDataType() { ForceDelete(); }

        /// Topic Name Property.
        ///
        /// @returns Topic Name defined in the constructor of this type.
        std::string TopicName() { return m_topicName; }

        /// Is this Amm Data Type registered on the DDS network?
        ///
        /// Runs a check if the topic name defined in the constructor has been registered on the DDS network.
        /// @returns True if the name defined in the constructor is registered.
        bool IsTypeRegistered();

        /// Creates a Publisher for the Amm Data Type defined in this template.
        ///
        /// @returns 0 if the Publisher is created successful.
        int CreatePublisher();

        /// Creates a Publisher for the Amm Data Type defined in this template.
        ///
        /// @param a Error message output.
        /// @returns 0 if the Publisher is created successful.
        int CreatePublisher(std::string &errmsg);

        /// Creates a Subscriber for the Amm Data Type defined in this template.
        ///
        /// @param a Pointer to a Listener Interface for setting the Subscriber upstream.
        /// @param b Reference to a function for callback on subscription event.
        /// @returns 0 if the Subscriber is created successful or one already exists.
        int CreateSubscriber(
                ListenerInterface *li, U *parentClass, void (U::*onEvent)(A &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Creates a Subscriber for the Amm Data Type defined in this template.
        ///
        /// @param a Error message output.
        /// @param b Pointer to a Listener Interface for setting the Subscriber upstream.
        /// @param c Reference to a function for callback on subscription event.
        /// @returns 0 if the Subscriber is created successful or one already exists.
        int CreateSubscriber(
                std::string &err, ListenerInterface *li, U *parentClass,
                void (U::*onEvent)(A &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Tells the Publisher to write type data to the DDS network.
        ///
        /// @param a Reference to the Amm Data Object that is to be written out to the DDS network.
        /// @returns 0 if the write is successful.
        int Write(A &a);

        /// Tells the Publisher to write type data to the DDS network.
        ///
        /// @param a Error message output.
        /// @param b Reference to the Amm Data Object that is to be written out to the DDS network.
        /// @returns 0 if the write was successful.
        int Write(std::string &errmsg, A &a);

        /// Callback for subscriber events.
        ///
        /// Calls the function pointer m_onEvent passing these same parameters.
        /// @param a Reference to the Amm Data Object that is being recieved from the DDS network.
        /// @param b Sample Info provided by the FastRTPS framework.
        /// @attention This is called by the entity that implements Listener Interface,
        /// which for internal use is DDS Manager, using the appropriate function override.
        /// @see ListenerInterface
        /// @see DDSManager
        void OnEvent(A &a, eprosima::fastrtps::SampleInfo_t *info);

        /// Delete this type and call cleanup routines for all associated types.
        ///
        /// @note Does not actually call `delete` on this.
        /// @returns 0 if delete is successful.
        int Delete();

        /// Delete this type and call cleanup routines for all associated types.
        ///
        /// @param a Error message output.
        /// @note Does not actually call `delete` on this.
        /// @returns 0 if delete is successful.
        int Delete(std::string &errmsg);

        /// Attempts to remove the Publisher associated with this type if one exists.
        ///
        /// @returns 0 if removal is successful or if publisher doesn't exist.
        int RemovePublisher();

        /// Attempts to remove the Publisher associated with this type if one exists.
        ///
        /// @param a Error message output.
        /// @returns 0 if removal is successful or if publisher doesn't exist.
        int RemovePublisher(std::string &errmsg);

        /// Attempts to remove the Subscriber associated with this type if one exists.
        ///
        /// @returns 0 if removal is successful or if subscriber doesn't exist.
        int RemoveSubscriber();

        /// Attempts to remove the Subscriber associated with this type if one exists.
        ///
        /// @param a Error message output.
        /// @returns 0 if removal is successful or if subscriber doesn't exist.
        int RemoveSubscriber(std::string &errmsg);
    };

    template<class T, class L, class A, class U>
    inline AmmDataType<T, L, A, U>::AmmDataType(
            const std::string topicName, eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl
    ) {

        m_topicName = topicName;

        m_participant = p;
        m_pubListener = pl;

        m_type = new T();
        m_type->setName(topicName.c_str());

        if (IsTypeRegistered()) {
            return;
        }

        eprosima::fastrtps::Domain::registerType(
                p, (eprosima::fastrtps::TopicDataType *) m_type
        );

    }

    template<class T, class L, class A, class U>
    inline AmmDataType<T, L, A, U>::AmmDataType(
            int &err, const std::string topicName, eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl
    ) {

        m_topicName = topicName;

        m_participant = p;
        m_pubListener = pl;

        m_type = new T();
        m_type->setName(topicName.c_str());

        if (IsTypeRegistered()) {
            err = 0;
            return;
        }

        bool isRegistered = false;

        isRegistered = eprosima::fastrtps::Domain::registerType(
                p, (eprosima::fastrtps::TopicDataType *) m_type
        );

        if (isRegistered) {
            err = 0;
        } else {
            err = 1;
        }
    }

    template<class T, class L, class A, class U>
    inline AmmDataType<T, L, A, U>::AmmDataType(
            int &err, std::string &errmsg, const std::string topicName,
            eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl
    ) {

        m_topicName = topicName;

        m_participant = p;
        m_pubListener = pl;

        m_type = new T();
        m_type->setName(topicName.c_str());

        if (IsTypeRegistered()) {
            err = 0;
            return;
        }

        bool isRegistered = false;

        isRegistered = eprosima::fastrtps::Domain::registerType(
                p, (eprosima::fastrtps::TopicDataType *) m_type
        );

        if (isRegistered) {
            err = 0;
        } else {
            errmsg = topicName + " failed to initialize due to unknown error.";
            err = 1;
        }
    }

    template<class T, class L, class A, class U>
    inline bool AmmDataType<T, L, A, U>::IsTypeRegistered() {

        // Output for getRegisteredType.
        // Not used for any significance other than to satisfy function requirements.
        eprosima::fastrtps::TopicDataType *type;

        return eprosima::fastrtps::Domain::getRegisteredType(
                m_participant,
                m_topicName.c_str(),
                &type
        );
    }

    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::CreatePublisher() {

        if (m_isPubInit) return 0;

        if (!IsTypeRegistered()) return 1;

        eprosima::fastrtps::PublisherAttributes pa;
        pa.topic.topicDataType = m_type->getName();
        pa.topic.topicName = m_topicName;
        if (m_topicName.compare("Physiology Waveform") == 0) {
            // LOG_INFO << "Setting phys waveform to Best Effort";
            pa.qos.m_reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
        }

        try {
            m_publisher = eprosima::fastrtps::Domain::createPublisher(
                    m_participant,
                    pa,
                    m_pubListener
            );
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }

        if (m_publisher == nullptr) {
            return 1;
        }

        m_isPubInit = true;

        return 0;
    }

    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::CreatePublisher(std::string &errmsg) {

        if (m_isPubInit) return 0;

        if (!IsTypeRegistered()) {
            errmsg = m_topicName + " is not properly initialized due to unknown error.";
            return 1;
        }

        eprosima::fastrtps::PublisherAttributes pa;
        pa.topic.topicDataType = m_type->getName();
        pa.topic.topicName = m_topicName;
        if (m_topicName.compare("Physiology Waveform") == 0) {
            // LOG_INFO << "Setting phys waveform to Best Effort";
            pa.qos.m_reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
        }

        try {
            m_publisher = eprosima::fastrtps::Domain::createPublisher(
                    m_participant,
                    pa,
                    m_pubListener
            );
        } catch (std::exception &e) {
            errmsg = "Create publisher failed -- ";
            errmsg.append(e.what());
            return 1;
        }

        if (m_publisher == nullptr) {
            errmsg = "Create publisher failed due to unknown error";
            return 1;
        }

        m_isPubInit = true;

        return 0;
    }

    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::CreateSubscriber(
            ListenerInterface *li, U *parentClass, void (U::*onEvent)(A &, eprosima::fastrtps::SampleInfo_t *)
    ) {

        if (m_isSubInit) return 0;

        if (!IsTypeRegistered()) return 1;

        // Create a new Subscriber Listener for the type defined in this template.
        m_listener = new L();

        // Set the Subscriber Listener upstream to the Listener Interface.
        m_listener->SetUpstream(li);

        m_parentClass = parentClass;

        eprosima::fastrtps::SubscriberAttributes sa;
        sa.topic.topicDataType = m_type->getName();
        sa.topic.topicName = m_topicName;

        try {
            m_subscriber = eprosima::fastrtps::Domain::createSubscriber(
                    m_participant,
                    sa,
                    m_listener
            );
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            delete m_listener;
            return 1;
        }

        if (m_subscriber == nullptr) {
            delete m_listener;
            return 1;
        }

        m_onEvent = onEvent;
        m_isSubInit = true;

        return 0;
    }


    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::CreateSubscriber(
            std::string &errmsg, ListenerInterface *li, U *parentClass,
            void (U::*onEvent)(A &, eprosima::fastrtps::SampleInfo_t *)
    ) {

        if (m_isSubInit) return 0;

        if (!IsTypeRegistered()) {
            errmsg = m_topicName + " is not properly initialized due to unknown error.";
            return 1;
        }

        m_listener = new L();
        m_listener->SetUpstream(li);

        m_parentClass = parentClass;

        eprosima::fastrtps::SubscriberAttributes sa;
        sa.topic.topicDataType = m_type->getName();
        sa.topic.topicName = m_topicName;

        try {
            m_subscriber = eprosima::fastrtps::Domain::createSubscriber(
                    m_participant,
                    sa,
                    m_listener
            );
        } catch (std::exception &e) {
            errmsg = "Create subscriber failed -- ";
            errmsg.append(e.what());
            delete m_listener;
            return 1;
        }

        if (m_subscriber == nullptr) {
            errmsg = "Create subscriber failed due to unknown error.";
            delete m_listener;
            return 1;
        }

        m_onEvent = onEvent;
        m_isSubInit = true;

        return 0;
    }

    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::Write(A &a) {

        if (!m_isPubInit) return 1;

        try {
            m_publisher->write(&a);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }

        return 0;
    }

    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::Write(std::string &errmsg, A &a) {

        if (!m_isPubInit) {
            errmsg = m_topicName + " publisher has not been created.";
            return 1;
        }

        try {
            m_publisher->write(&a);
        } catch (std::exception &e) {
            errmsg = "Write failed -- ";
            errmsg.append(e.what());
            return 1;
        }

        return 0;
    }

    template<class T, class L, class A, class U>
    inline void AmmDataType<T, L, A, U>::OnEvent(A &a, eprosima::fastrtps::SampleInfo_t *info) {

        // NOTE:
        // Is called by the entity that is implementing Listener Interface.
        // Calls the function pointer passing these same parameters.
        //
        // Function pointer points to a function defined by the user when
        // Create Subscriber is called.

        // NOTE:
        // To use function pointers that belong to classes, a reference to both the function and the class
        // it belongs to must be held and invoked.

        // Using pointer to parent class to invoke member method.
        (m_parentClass->*m_onEvent)(a, info);
    }

    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::Delete() {

        RemovePublisher();
        RemoveSubscriber();

        if (!eprosima::fastrtps::Domain::unregisterType(m_participant, m_topicName.c_str())) {
            return 1;
        }

        delete m_type;

        return 0;
    }

    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::Delete(std::string &errmsg) {

        if (RemovePublisher() != 0) {
            errmsg = "An unknown error occured while removing " + m_topicName + " publisher.";
            return 1;
        }

        if (RemoveSubscriber(errmsg) != 0) {
            errmsg = "An unknown error occured while removing " + m_topicName + " subscriber -- " + errmsg;
            return 1;
        }

        if (!eprosima::fastrtps::Domain::unregisterType(m_participant, m_topicName.c_str())) {
            errmsg = "An unknown error occured while decomissioning " + m_topicName + ".";
            return 1;
        }

        delete m_type;

        return 0;
    }

    template<class T, class L, class A, class U>
    inline void AmmDataType<T, L, A, U>::ForceDelete() {

        if (m_isPubInit) eprosima::fastrtps::Domain::removePublisher(m_publisher);
        if (m_isSubInit) eprosima::fastrtps::Domain::removeSubscriber(m_subscriber);

        m_isPubInit = false;
        m_isSubInit = false;

        delete m_type;
        delete m_listener;

        eprosima::fastrtps::Domain::unregisterType(m_participant, m_topicName.c_str());
    }

    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::RemovePublisher() {
        if (!m_isPubInit) return 0;

        if (!eprosima::fastrtps::Domain::removePublisher(m_publisher)) return 1;

        m_isPubInit = false;
        return 0;
    }

    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::RemovePublisher(std::string &errmsg) {
        if (!m_isPubInit) return 0;

        if (!eprosima::fastrtps::Domain::removePublisher(m_publisher)) {
            errmsg = m_topicName + " publisher could not be removed.";
            return 1;
        }

        m_isPubInit = false;
        return 0;
    }

    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::RemoveSubscriber() {
        if (!m_isSubInit) return 0;

        if (!eprosima::fastrtps::Domain::removeSubscriber(m_subscriber)) return 1;

        m_isSubInit = false;
        delete m_listener;
        return 0;
    }

    template<class T, class L, class A, class U>
    inline int AmmDataType<T, L, A, U>::RemoveSubscriber(std::string &errmsg) {
        if (!m_isSubInit) return 0;

        if (!eprosima::fastrtps::Domain::removeSubscriber(m_subscriber)) {
            errmsg = m_topicName + " subscriber could not be removed.";
            return 1;
        }

        m_isSubInit = false;
        delete m_listener;
        return 0;
    }


/// AMM template class for handling AMM-DDS topics.
///
/// @attention This specialization should be used if a stand-alone function is being used to
/// receive subscribed events. This specialization doesn't manage a reference to another object.
///
/// The following template variables are examples of how to use this tempate.
/// T = AMM::AssessmentPubSubType
/// L = DDS_Listeners::AssessmentListener
/// A = AMM::Assessment
    template<class T, class L, class A>
    class AmmDataType<T, L, A, void> {
    private:

        /// Pointer to the DDS Participant managed by the DDS Manager.
        eprosima::fastrtps::Participant *m_participant;

        /// Pointer to the Publisher Listener managed by the DDS Manager.
        DDS_Listeners::PubListener *m_pubListener;

        /// Pointer to the Amm PubSub Type defined in this template.
        ///
        /// @note Is managed internally by this template class.
        /// @note e.g. T = AMM::AssessmentPubSubType
        T *m_type;

        /// Pointer to the Subscriber Listener defined in this template.
        ///
        /// @note Is managed internally by this template class.
        /// @note e.g. L = DDS_Listeners::AssessmentListener.
        L *m_listener;

        /// Publisher of the Amm Data Type defined by this template.
        eprosima::fastrtps::Publisher *m_publisher;

        /// Subscriber of the Amm Data Type defined by this template.
        eprosima::fastrtps::Subscriber *m_subscriber;

        /// Is the publisher of this type initialized?
        ///
        /// @note Prevents access to a null publisher pointer.
        bool m_isPubInit = false;

        /// Is the subscriber of this type initialized?
        ///
        /// @note Prevent access to a null subscriber pointer.
        bool m_isSubInit = false;

        /// Name of this AMM Data Type that is to be registered on the DDS network.
        std::string m_topicName;

        /// Pointer to the function that is called when a subscribed event occurs.
        ///
        /// @note Takes data from an object type that is defined by this template.
        /// @note e.g A = AMM::Assessment.
        void (*m_onEvent)(A &, eprosima::fastrtps::SampleInfo_t *);

    private:

        /// Attempt to clean up all objects created or initialized by this class.
        /// @note Will throw silent errors if any occur during cleanup, but will continue to remove all used objects.
        void ForceDelete();

    public:

        /// Constructor for initializing an Amm Data Type.
        ///
        /// @param a Name of this type that willb e registered on the DDS network.
        /// @param b DDS Participant that is managed from the DDS Manager.
        /// @param c DDS Publisher Listener that is managed from the DDS Manager.
        AmmDataType(const std::string topicName, eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl);

        /// Constructor for initializing an Amm Data Type.
        ///
        /// This is primarily used for error handling since the internal logic of this constructor
        /// can throw errors and end the routine prematurely.
        /// @param a Error code output. Is 0 if routine is successful.
        /// @param b Name of this type that willb e registered on the DDS network.
        /// @param c DDS Participant that is managed from the DDS Manager.
        /// @param d DDS Publisher Listener that is managed from the DDS Manager.
        AmmDataType(
                int &err, const std::string topicName,
                eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl
        );

        /// Constructor for initializing an Amm Data Type.
        ///
        /// This is primarily used for error handling since the internal logic of this constructor
        /// can throw errors and end the routine prematurely.
        /// @param a Error code output. Is 0 if routine is successful.
        /// @param b Error message output describing the error if any.
        /// @param c Name of this type that willb e registered on the DDS network.
        /// @param d DDS Participant that is managed from the DDS Manager.
        /// @param e DDS Publisher Listener that is managed from the DDS Manager.
        AmmDataType(
                int &err, std::string &errmsg, const std::string topicName,
                eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl
        );

        /// Default deconstructor.
        ///
        /// Calls Force Delete when used.
        /// @note It is safe to call the deconstructor on this as opposed to calling Shutdown since Force Delete
        /// will ensure that a cleanup routine is at least attempted if not already, however it is not recommened.
        ~AmmDataType() { ForceDelete(); }

        /// Topic Name Property.
        ///
        /// @returns Topic Name defined in the constructor of this type.
        std::string TopicName() { return m_topicName; }

        /// Is this Amm Data Type registered on the DDS network?
        ///
        /// Runs a check if the topic name defined in the constructor has been registered on the DDS network.
        /// @returns True if the name defined in the constructor is registered.
        bool IsTypeRegistered();

        /// Creates a Publisher for the Amm Data Type defined in this template.
        ///
        /// @returns 0 if the Publisher is created successful.
        int CreatePublisher();

        /// Creates a Publisher for the Amm Data Type defined in this template.
        ///
        /// @param a Error message output.
        /// @returns 0 if the Publisher is created successful.
        int CreatePublisher(std::string &errmsg);

        /// Creates a Subscriber for the Amm Data Type defined in this template.
        ///
        /// @param a Pointer to a Listener Interface for setting the Subscriber upstream.
        /// @param b Reference to a function for callback on subscription event.
        /// @returns 0 if the Subscriber is created successful or one already exists.
        int CreateSubscriber(
                ListenerInterface *li, void (*onEvent)(A &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Creates a Subscriber for the Amm Data Type defined in this template.
        ///
        /// @param a Error message output.
        /// @param b Pointer to a Listener Interface for setting the Subscriber upstream.
        /// @param c Reference to a function for callback on subscription event.
        /// @returns 0 if the Subscriber is created successful or one already exists.
        int CreateSubscriber(
                std::string &err, ListenerInterface *li,
                void (*onEvent)(A &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Tells the Publisher to write type data to the DDS network.
        ///
        /// @param a Reference to the Amm Data Object that is to be written out to the DDS network.
        /// @returns 0 if the write is successful.
        int Write(A &a);

        /// Tells the Publisher to write type data to the DDS network.
        ///
        /// @param a Error message output.
        /// @param b Reference to the Amm Data Object that is to be written out to the DDS network.
        /// @returns 0 if the write was successful.
        int Write(std::string &errmsg, A &a);

        /// Callback for subscriber events.
        ///
        /// Calls the function pointer m_onEvent passing these same parameters.
        /// @param a Reference to the Amm Data Object that is being recieved from the DDS network.
        /// @param b Sample Info provided by the FastRTPS framework.
        /// @attention This is called by the entity that implements Listener Interface,
        /// which for internal use is DDS Manager, using the appropriate function override.
        /// @see ListenerInterface
        /// @see DDSManager
        void OnEvent(A &a, eprosima::fastrtps::SampleInfo_t *info);

        /// Delete this type and call cleanup routines for all associated types.
        ///
        /// @note Does not actually call `delete` on this.
        /// @returns 0 if delete is successful.
        int Delete();

        /// Delete this type and call cleanup routines for all associated types.
        ///
        /// @param a Error message output.
        /// @note Does not actually call `delete` on this.
        /// @returns 0 if delete is successful.
        int Delete(std::string &errmsg);

        /// Attempts to remove the Publisher associated with this type if one exists.
        ///
        /// @returns 0 if removal is successful or if publisher doesn't exist.
        int RemovePublisher();

        /// Attempts to remove the Publisher associated with this type if one exists.
        ///
        /// @param a Error message output.
        /// @returns 0 if removal is successful or if publisher doesn't exist.
        int RemovePublisher(std::string &errmsg);

        /// Attempts to remove the Subscriber associated with this type if one exists.
        ///
        /// @returns 0 if removal is successful or if subscriber doesn't exist.
        int RemoveSubscriber();

        /// Attempts to remove the Subscriber associated with this type if one exists.
        ///
        /// @param a Error message output.
        /// @returns 0 if removal is successful or if subscriber doesn't exist.
        int RemoveSubscriber(std::string &errmsg);
    };

    template<class T, class L, class A>
    inline AmmDataType<T, L, A, void>::AmmDataType(
            const std::string topicName, eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl
    ) {

        m_topicName = topicName;

        m_participant = p;
        m_pubListener = pl;

        m_type = new T();
        m_type->setName(topicName.c_str());

        if (IsTypeRegistered()) {
            return;
        }

        eprosima::fastrtps::Domain::registerType(
                p, (eprosima::fastrtps::TopicDataType *) m_type
        );

    }

    template<class T, class L, class A>
    inline AmmDataType<T, L, A, void>::AmmDataType(
            int &err, const std::string topicName, eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl
    ) {

        m_topicName = topicName;

        m_participant = p;
        m_pubListener = pl;

        m_type = new T();
        m_type->setName(topicName.c_str());

        if (IsTypeRegistered()) {
            err = 0;
            return;
        }

        bool isRegistered = false;

        isRegistered = eprosima::fastrtps::Domain::registerType(
                p, (eprosima::fastrtps::TopicDataType *) m_type
        );

        if (isRegistered) {
            err = 0;
        } else {
            err = 1;
        }
    }

    template<class T, class L, class A>
    inline AmmDataType<T, L, A, void>::AmmDataType(
            int &err, std::string &errmsg, const std::string topicName,
            eprosima::fastrtps::Participant *p, DDS_Listeners::PubListener *pl
    ) {

        m_topicName = topicName;

        m_participant = p;
        m_pubListener = pl;

        m_type = new T();
        m_type->setName(topicName.c_str());

        if (IsTypeRegistered()) {
            err = 0;
            return;
        }

        bool isRegistered = false;

        isRegistered = eprosima::fastrtps::Domain::registerType(
                p, (eprosima::fastrtps::TopicDataType *) m_type
        );

        if (isRegistered) {
            err = 0;
        } else {
            errmsg = topicName + " failed to initialize due to unknown error.";
            err = 1;
        }
    }

    template<class T, class L, class A>
    inline bool AmmDataType<T, L, A, void>::IsTypeRegistered() {

        // Output for getRegisteredType.
        // Not used for any significance other than to satisfy function requirements.
        eprosima::fastrtps::TopicDataType *type;

        return eprosima::fastrtps::Domain::getRegisteredType(
                m_participant,
                m_topicName.c_str(),
                &type
        );
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::CreatePublisher() {

        if (m_isPubInit) return 0;

        if (!IsTypeRegistered()) return 1;

        eprosima::fastrtps::PublisherAttributes pa;
        pa.topic.topicDataType = m_type->getName();
        pa.topic.topicName = m_topicName;

        try {
            m_publisher = eprosima::fastrtps::Domain::createPublisher(
                    m_participant,
                    pa,
                    m_pubListener
            );
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }

        if (m_publisher == nullptr) {
            return 1;
        }

        m_isPubInit = true;

        return 0;
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::CreatePublisher(std::string &errmsg) {

        if (m_isPubInit) return 0;

        if (!IsTypeRegistered()) {
            errmsg = m_topicName + " is not properly initialized due to unknown error.";
            return 1;
        }

        eprosima::fastrtps::PublisherAttributes pa;
        pa.topic.topicDataType = m_type->getName();
        pa.topic.topicName = m_topicName;

        try {
            m_publisher = eprosima::fastrtps::Domain::createPublisher(
                    m_participant,
                    pa,
                    m_pubListener
            );
        } catch (std::exception &e) {
            errmsg = "Create publisher failed -- ";
            errmsg.append(e.what());
            return 1;
        }

        if (m_publisher == nullptr) {
            errmsg = "Create publisher failed due to unknown error";
            return 1;
        }

        m_isPubInit = true;

        return 0;
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::CreateSubscriber(
            ListenerInterface *li, void (*onEvent)(A &, eprosima::fastrtps::SampleInfo_t *)
    ) {

        if (m_isSubInit) return 0;

        if (!IsTypeRegistered()) return 1;

        // Create a new Subscriber Listener for the type defined in this template.
        m_listener = new L();

        // Set the Subscriber Listener upstream to the Listener Interface.
        m_listener->SetUpstream(li);


        eprosima::fastrtps::SubscriberAttributes sa;
        sa.topic.topicDataType = m_type->getName();
        sa.topic.topicName = m_topicName;

        try {
            m_subscriber = eprosima::fastrtps::Domain::createSubscriber(
                    m_participant,
                    sa,
                    m_listener
            );
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            delete m_listener;
            return 1;
        }

        if (m_subscriber == nullptr) {
            delete m_listener;
            return 1;
        }

        m_onEvent = onEvent;
        m_isSubInit = true;

        return 0;
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::CreateSubscriber(
            std::string &errmsg, ListenerInterface *li, void (*onEvent)(A &, eprosima::fastrtps::SampleInfo_t *)
    ) {

        if (m_isSubInit) return 0;

        if (!IsTypeRegistered()) {
            errmsg = m_topicName + " is not properly initialized due to unknown error.";
            return 1;
        }

        m_listener = new L();
        m_listener->SetUpstream(li);


        eprosima::fastrtps::SubscriberAttributes sa;
        sa.topic.topicDataType = m_type->getName();
        sa.topic.topicName = m_topicName;

        try {
            m_subscriber = eprosima::fastrtps::Domain::createSubscriber(
                    m_participant,
                    sa,
                    m_listener
            );
        } catch (std::exception &e) {
            errmsg = "Create subscriber failed -- ";
            errmsg.append(e.what());
            delete m_listener;
            return 1;
        }

        if (m_subscriber == nullptr) {
            errmsg = "Create subscriber failed due to unknown error.";
            delete m_listener;
            return 1;
        }

        m_onEvent = onEvent;
        m_isSubInit = true;

        return 0;
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::Write(A &a) {

        if (!m_isPubInit) return 1;

        try {
            m_publisher->write(&a);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }

        return 0;
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::Write(std::string &errmsg, A &a) {

        if (!m_isPubInit) {
            errmsg = m_topicName + " publisher has not been created.";
            return 1;
        }

        try {
            m_publisher->write(&a);
        } catch (std::exception &e) {
            errmsg = "Write failed -- ";
            errmsg.append(e.what());
            return 1;
        }

        return 0;
    }

    template<class T, class L, class A>
    inline void AmmDataType<T, L, A, void>::OnEvent(A &a, eprosima::fastrtps::SampleInfo_t *info) {

        // NOTE:
        // Is called by the entity that is implementing Listener Interface.
        // Calls the function pointer passing these same parameters.
        //
        // Function pointer points to a function defined by the user when
        // Create Subscriber is called.

        // NOTE:
        // To use function pointers that belong to classes, a reference to both the function and the class
        // it belongs to must be held and invoked.

        // Using pointer to parent class to invoke member method.
        m_onEvent(a, info);
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::Delete() {

        RemovePublisher();
        RemoveSubscriber();

        if (!eprosima::fastrtps::Domain::unregisterType(m_participant, m_topicName.c_str())) {
            return 1;
        }

        delete m_type;

        return 0;
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::Delete(std::string &errmsg) {

        if (RemovePublisher() != 0) {
            errmsg = "An unknown error occured while removing " + m_topicName + " publisher.";
            return 1;
        }

        if (RemoveSubscriber(errmsg) != 0) {
            errmsg = "An unknown error occured while removing " + m_topicName + " subscriber -- " + errmsg;
            return 1;
        }

        if (!eprosima::fastrtps::Domain::unregisterType(m_participant, m_topicName.c_str())) {
            errmsg = "An unknown error occured while decomissioning " + m_topicName + ".";
            return 1;
        }

        delete m_type;

        return 0;
    }

    template<class T, class L, class A>
    inline void AmmDataType<T, L, A, void>::ForceDelete() {

        if (m_isPubInit) eprosima::fastrtps::Domain::removePublisher(m_publisher);
        if (m_isSubInit) eprosima::fastrtps::Domain::removeSubscriber(m_subscriber);

        m_isPubInit = false;
        m_isSubInit = false;

        delete m_type;
        delete m_listener;

        eprosima::fastrtps::Domain::unregisterType(m_participant, m_topicName.c_str());
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::RemovePublisher() {
        if (!m_isPubInit) return 0;

        if (!eprosima::fastrtps::Domain::removePublisher(m_publisher)) return 1;

        m_isPubInit = false;
        return 0;
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::RemovePublisher(std::string &errmsg) {
        if (!m_isPubInit) return 0;

        if (!eprosima::fastrtps::Domain::removePublisher(m_publisher)) {
            errmsg = m_topicName + " publisher could not be removed.";
            return 1;
        }

        m_isPubInit = false;
        return 0;
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::RemoveSubscriber() {
        if (!m_isSubInit) return 0;

        if (!eprosima::fastrtps::Domain::removeSubscriber(m_subscriber)) return 1;

        m_isSubInit = false;
        delete m_listener;
        return 0;
    }

    template<class T, class L, class A>
    inline int AmmDataType<T, L, A, void>::RemoveSubscriber(std::string &errmsg) {
        if (!m_isSubInit) return 0;

        if (!eprosima::fastrtps::Domain::removeSubscriber(m_subscriber)) {
            errmsg = m_topicName + " subscriber could not be removed.";
            return 1;
        }

        m_isSubInit = false;
        delete m_listener;
        return 0;
    }


} /// namespace AMM
