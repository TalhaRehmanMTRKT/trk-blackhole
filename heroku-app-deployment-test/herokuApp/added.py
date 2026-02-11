import random


class YourClass:
    """
    This class allows serializing/ deserializing the action space.

    It should not be used inside an :attr:`grid2op.Environment.Environment` , as some functions of the action might not
    be compatible with the serialization, especially the checking of whether or not an action is legal or not.

    Attributes
    ----------

    actionClass: ``type``
        Type used to build the :attr:`SerializableActionSpace.template_act`

    _template_act: :class:`BaseAction`
        An instance of the "*actionClass*" provided used to provide higher level utilities, such as the size of the
        action (see :func:`Action.size`) or to sample a new Action (see :func:`grid2op.Action.Action.sample`)

    """

    def __init__(self):
        """
        Your initialization method here.
        """
        pass

    def set_bus(self, name_element, new_bus, extremity=None, substation=None, type_element=None, previous_action=None):
        """
        Utilities to set the bus of a single element if you give its name. **NB** Setting a bus has the effect to
        assign the object to this bus. If it was before that connected to bus 1, and you assign it to bus 1 (*new_bus*
        = 1) it will stay on bus 1. If it was on bus 2 (and you still assign it to bus 1) it will be moved to bus 2.
        1. It should not be mixed up with :func:`ActionSpace.change_bus`.

        If the parameter "*previous_action*" is not ``None``, then the action given to it is updated (in place) and
        returned.

        Parameters
        ----------
        name_element: str
            The name of the element you want to change the bus.

        new_bus: int
            Id of the new bus to connect the object to.

        extremity: str, optional
            "or" or "ext" for origin or extremity, ignored if the element is not a powerline.

        substation: int, optional
            Its substation ID, if you know it will increase the performance. Otherwise, the method will search for it.

        type_element: str, optional
            Type of the element to look for. It is here to speed up the computation. One of "line", "gen" or "load".

        previous_action: BaseAction, optional
            The (optional) action to update. It should be of the same type as :attr:`ActionSpace.actionClass`.

        Returns
        -------
        BaseAction
            The action with the modification implemented.

        Raises
        ------
        AmbiguousAction
            If *previous_action* has not the same type as :attr:`ActionSpace.actionClass`.

        Examples
        --------
        You can use it this way:

        >>> import grid2op
        >>> env = grid2op.make("l2rpn_case14_sandbox")

        # set bus of element named 'gen_1_0' to bus 2
        >>> setbus_gen_0 = env.action_space.set_bus('gen_1_0', new_bus=2, type_element="gen")

        # are not forced to specify the element types (example with load set to bus 1)
        >>> setbus_load_1 = env.action_space.set_bus('load_2_1', new_bus=1)

        # dealing with powerline, you can affect one of its extremity
        # (handy when you don't know on which substation it is located)
        >>> setbus_line_8_or = env.action_space.set_bus('5_11_8', new_bus=1, extremity="or")

        # and you can combine the actions with:
        >>> setbus_line_14_ex = env.action_space.set_bus('12_13_14', new_bus=2, extremity="ex")
        >>> setbus_line_14_ex_load_2 = env.action_space.set_bus("load_3_2", new_bus=1,
                                                                previous_action=setbus_line_14_ex)
        >>> print(setbus_line_14_ex_load_2)
        # be careful, "setbus_line_14_ex" is affected and is in fact equal to
        # "setbus_line_14_ex_load_2"
        # after the last call!
        """
        # implementation here

    def addition(self, a, b):
        """
        Performs addition of two numbers.

        Parameters
        ----------
        a: int or float
            The first operand.

        b: int or float
            The second operand.

        Returns
        -------
        int or float
            The result of the addition operation.

        Examples
        --------
        >>> calc = YourClass()
        >>> calc.addition(2, 3)
        5
        >>> calc.addition(2.5, 1.5)
        4.0
        """
        return a + b

    def subtraction(self, a, b):
        """
        Performs subtraction of two numbers.

        Parameters
        ----------
        a: int or float
            The first operand.

        b: int or float
            The second operand.

        Returns
        -------
        int or float
            The result of the subtraction operation.

        Examples
        --------
        >>> calc = YourClass()
        >>> calc.subtraction(5, 3)
        2
        >>> calc.subtraction(4.5, 2.5)
        2.0
        """
        return a - b
